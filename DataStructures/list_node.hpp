#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

#include "node.hpp"

template <class T>
class list_node : public node<T>
{
public:
	list_node() = delete;
	explicit list_node(const T& data, list_node<T>* next = nullptr, list_node<T>* previous = nullptr);
	list_node(const list_node<T>& copy); 
	list_node<T>& operator=(const list_node<T>& rhs);

	list_node(list_node<T>&& copy) noexcept;
	list_node<T>& operator=(list_node<T>&& rhs) noexcept;

	list_node<T>* get_next() noexcept;
	list_node<T>* get_next() const noexcept;
	list_node<T>* get_previous() noexcept;
	list_node<T>* get_previous() const noexcept;

	void set_next(list_node<T>* const next) noexcept;
	void set_previous(list_node<T>* const previous) noexcept;

	~list_node() = default;
private:
	list_node<T>* next_{ nullptr };
	list_node<T>* previous_{ nullptr };
	
};

template <class T>
list_node<T>::list_node(const T& data, list_node<T>* next, list_node<T>* previous) 
	: node<T>(data)
{
	try
	{
		next_ = next;
		previous_ = previous;
	}
	catch (std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}
}

template <class T>
list_node<T>::list_node(const list_node<T>& copy)
	: node<T>(copy.get_data())
{
	*this = copy;
}

template <class T>
list_node<T>& list_node<T>::operator=(const list_node<T>& rhs)
{
	if (this != &rhs)
	{
		if (next_ != nullptr) delete next_;
		if (previous_ != nullptr) delete previous_;

		this->set_data(rhs.get_data());
		next_ = rhs.get_next();
		previous_ = rhs.get_previous();
	}

	return *this;
}

template <class T>
list_node<T>::list_node(list_node<T>&& copy) noexcept
{
	*this = std::move(copy);
}

template <class T>
list_node<T>& list_node<T>::operator=(list_node<T>&& rhs) noexcept
{
	if (this != &rhs)
	{
		if (next_ != nullptr) delete next_;
		if (previous_ != nullptr) delete previous_;

		next_ = new list_node<T>(rhs.get_next());
		previous_ = new list_node<T>(rhs.get_previous());
	}

	return *this;
}

template <class T>
list_node<T>* list_node<T>::get_next() noexcept
{
	return next_;
}

template <class T>
list_node<T>* list_node<T>::get_next() const noexcept
{
	return next_;
}

template <class T>
list_node<T>* list_node<T>::get_previous() noexcept
{
	return previous_;
}

template <class T>
list_node<T>* list_node<T>::get_previous() const noexcept
{
	return previous_;
}

template <class T>
void list_node<T>::set_next(list_node<T>* const next) noexcept
{
	next_ = next;
}

template <class T>
void list_node<T>::set_previous(list_node<T>* const previous) noexcept
{
	previous_ = previous;
}

#endif
