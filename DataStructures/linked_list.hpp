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

		head_ = rhs.head_;
		tail_ = rhs.tail_;
		length_ = rhs.length_;
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

		head_ = rhs.head_;
		tail_ = rhs.tail_;
		length_ = rhs.length_;
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

	
}

//template <class T>
//void linked_list<T>::extract(const T& data)
//{
//	// extract deletes the node
//
//	//1 auto current = head
//	//2 while (current != nullptr && current->get_data() != data)
//	//		{ current = current->next }
//	//3 if (current->get_data() == data) 
//	//		{ 
//	//	if(empty) throw exemption
//	//	else:
//	//	if head
//	//	head->next->previous = nullptr
//	//	head = head_->next
//	//	if tail:
//	//	tail->previous->next = nullptr
//	//	tail = tail->previous
//	//  if middle (not head or tail):
//	//4 current->next->previous = current->previous
//	//5 current->previous->next = current->next
//	//
//	//6 delete current
//	//7 decriment length
//}

//template <class T>
//void linked_list<T>::insert_after(const T& data, const T& after)
//{
//	//insert(data) 6, current(after) 5
//
//	//1 create new node(previous=current, next=current->next)
//	//2 new_node-next-previous=new_node
//	//3 current-next = new_node 
//}

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

//template <class T>
//void linked_list<T>::shuffle()
//{
//	std::random_device device;
//	std::mt19937 generator(device());
//	std::uniform_int_distribution<int> distribution(1, length_);
//
//	for(size_t i = 0; i < length_; ++i)
//	{
//		auto i1 = distribution(generator) - 1;
//		auto i2 = distribution(generator) - 1;
//		this->insert_after(this[i1], this[i2]);
//	}
//}

template <class T>
void linked_list<T>::clear() noexcept
{
	list_node<T>* current = head_;
	while (current != nullptr) {
		list_node<T>* next = current->get_next();
		delete current;
		current = next;
	}
	head_ = nullptr;
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
