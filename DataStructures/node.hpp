#ifndef NODE_HPP
#define NODE_HPP
#include "adt_exception.hpp"
#include <algorithm>

template <class T>
class node
{
public:
	explicit node() = delete;
	explicit node(T data); //: data_(std::move(data)){}

	node(const node& copy);
	node<T>& operator=(const node& copy);

	node(node && copy) noexcept;
	node<T>& operator=(node&& copy) noexcept;

	virtual ~node() = default;

	T& get_data() noexcept; 
	T get_data() const;
	void set_data(const T& data);

private:
	T data_;
};

template <class T>
node<T>::node(T data) : data_( std::move(data)){}


template <class T>
node<T>::node(const node& copy)
{
	*this = copy;
}

template <class T>
node<T>& node<T>::operator=(const node& copy)
{
	if(this != &copy)
	{
		data_ = copy.get_data();
	}
	return *this;
}

template <class T>
node<T>::node(node&& copy) noexcept
{
	*this = std::move(copy);
}

template <class T>
node<T>& node<T>::operator=(node&& copy) noexcept
{
	if (this != copy)
	{	
		data_ = copy.get_data();
	}
	return *this;
}

template <class T>
T& node<T>::get_data() noexcept
{
	return data_;
}

template <class T>
T node<T>::get_data() const
{
	return data_;
}

template <class T>
void node<T>::set_data(const T& data)
{
	try
	{
		data_ = data;
	}
	catch (const std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}
}

#endif
