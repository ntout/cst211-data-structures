#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "adt_exception.hpp"
#include "list_node.hpp"
#include <random>

template <class T>
class linked_list
{
public:
	linked_list() = default;
	linked_list(const linked_list& copy);
	linked_list& operator=(const linked_list& rhs);

	linked_list(linked_list&& copy) noexcept;
	linked_list& operator=(linked_list&& rhs) noexcept;

	explicit operator bool() const;

	void append(const T& data);
	void prepend(const T& data);
	void remove_last();
	void remove_first();
	void extract(const T& data);
	void insert_after(const T& data, const T& after);
	void insert_before(const T& data, const T& before);

	linked_list<T>& merge(const linked_list<T>& rhs);
	//void shuffle();

	void clear() noexcept;
	T& last();
	T last() const;
	T& first();
	T first() const;
	list_node<T>* get_head() const noexcept;
	list_node<T>* get_tail() const noexcept;
	bool is_empty() const noexcept;
	size_t get_length() const noexcept;

	~linked_list();

private:
	list_node<T>* head_ {nullptr};
	list_node<T>* tail_ {nullptr};
	size_t length_ {0};
};

template <class T>
linked_list<T>::linked_list(const linked_list& copy)
{
	*this = copy;
}

template <class T>
linked_list<T>& linked_list<T>::operator=(const linked_list& rhs)
{
	if (this != &rhs)
	{
		if (head_ != nullptr) delete head_;
		if (tail_ != nullptr) delete tail_;

		head_ = rhs.get_head();
		tail_ = rhs.get_tail();
		length_ = rhs.get_length();
	}

	return *this;
}

template <class T>
linked_list<T>::linked_list(linked_list&& copy) noexcept
{
	*this = std::move(copy);
}

template <class T>
linked_list<T>& linked_list<T>::operator=(linked_list&& rhs) noexcept
{
	if (this != &rhs)
	{
		if (head_ != nullptr) delete head_;
		if (tail_ != nullptr) delete tail_;

		head_ = rhs.get_head();
		tail_ = rhs.get_tail();
		length_ = rhs.get_length();
	}

	return *this;
}

template <class T>
linked_list<T>::operator bool() const
{
	return (*this != 0);
}

template <class T>
void linked_list<T>::append(const T& data)
{
	if (head_ == nullptr && tail_ == nullptr)
	{
		auto* node = new list_node<T>(data);
		head_ = node;
		tail_ = node;
		length_ += 1;
	}
	else if (head_ != nullptr && tail_ != nullptr)
	{
		auto* node = new list_node<T>(data);
		node->set_previous(tail_);
		tail_->set_next(node);
		tail_ = node;
		length_ += 1;
	}
}

template <class T>
void linked_list<T>::prepend(const T& data)
{
	if (head_ == nullptr && tail_ == nullptr)
	{
		auto* node = new list_node<T>(data);
		head_ = node;
		tail_ = node;
		length_ += 1;
	}
	else if (head_ != nullptr && tail_ != nullptr)
	{
		auto* node = new list_node<T>(data);
		node->set_next(head_);
		head_->set_previous(node);
		head_ = node;
		length_ += 1;
	}
}

template <class T>
void linked_list<T>::remove_last()
{
	if(tail_ != nullptr)
	{
		auto previous = tail_->get_previous();
		previous->set_next(nullptr);

		delete tail_;

		tail_ = previous;

		length_ -= 1;
	}
}

template <class T>
void linked_list<T>::remove_first()
{
	if (head_ != nullptr)
	{
		auto next = head_->get_next();
		next->set_previous(nullptr);

		delete head_;

		head_ = next;

		length_ -= 1;
	}
}

template <class T>
void linked_list<T>::extract(const T& data)
{
	if (!this->is_empty())
	{
		auto current = head_;
		while(current->get_data() != data)
		{
			current = current->get_next();
		}

		if(current == head_)
		{
			this->remove_first();
		}
		else if (current == tail_)
		{
			this->remove_last();
		}
		else
		{
			auto prev = current->get_previous();
			auto next = current->get_next();
			prev->set_next(next);
			next->set_previous(prev);

			delete current;
			length_ -= 1;
		}
	}
}

template <class T>
void linked_list<T>::insert_after(const T& data, const T& after)
{
	if (!this->is_empty())
	{
		auto current = tail_;
		while (current->get_data() != after)
		{
			current = current->get_next();
		}
		if (current == tail_)
		{
			this->append(data);
		}
		else
		{
			auto* node = new list_node<T>(data);
			node->set_previous(current);
			node->set_next(current->get_next());

			current->get_next()->set_previous(node);
			current->set_next(node);

			length_ += 1;
		}
	}
}

template <class T>
void linked_list<T>::insert_before(const T& data, const T& before)
{
	if (!this->is_empty())
	{
		auto current = head_;
		while (current->get_data() != before)
		{
			current = current->get_next();
		}
		if (current == head_)
		{
			this->prepend(data);
		}
		else
		{
			auto* node = new list_node<T>(data);
			node->set_previous(current->get_previous());
			node->set_next(current);

			current->get_previous()->set_next(node);
			current->set_previous(node);

			length_ += 1;
		}
	}
}


template <class T>
linked_list<T>& linked_list<T>::merge(const linked_list<T>& rhs)
{
	
	linked_list<T> temp;
	const size_t length = length_ + rhs.get_length();

	for(auto i = 0; i < length; ++i)
	{
		if(this[i] == true)
		{
			temp.append(this[i]);
		}
		if(rhs[i] == true)
		{
			temp.append(rhs[i]);
		}
	}

	this = temp;
	delete temp;
	delete rhs;

	return this;
}

template <class T>
void linked_list<T>::clear() noexcept
{
	if (!this->is_empty())
	{
		auto* current = head_;
		while (current != nullptr) {
			list_node<T>* next = current->get_next();
			if (current != nullptr) delete current;
			current = next;
		}
	}
	head_ = nullptr;
	tail_ = nullptr;
}

template <class T>
T& linked_list<T>::last()
{
	return tail_->get_data();
}

template <class T>
T linked_list<T>::last() const
{
	return tail_->get_data();
}

template <class T>
T& linked_list<T>::first()
{
	return head_->get_data();
}

template <class T>
T linked_list<T>::first() const
{
	return head_->get_data();
}

template <class T>
list_node<T>* linked_list<T>::get_head() const noexcept
{
	return head_;
}

template <class T>
list_node<T>* linked_list<T>::get_tail() const noexcept
{
	return tail_;
}

template <class T>
bool linked_list<T>::is_empty() const noexcept
{
	return length_ == 0;
}

template <class T>
size_t linked_list<T>::get_length() const noexcept
{
	return length_;
}

template <class T>
linked_list<T>::~linked_list()
{
	this->clear();
}

#endif
