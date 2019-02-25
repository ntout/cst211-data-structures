#ifndef NODE_HPP
#define NODE_HPP
#include "adt_exception.hpp"
#include <algorithm>

template <class T>
class node
{
public:
	explicit node() = delete;
	explicit node(T data): data_(std::move(data)){}

	node(const node& copy) { *this = copy;  }
	node<T>& operator=(const node& copy);

	node(node && copy) noexcept { *this = std::move(copy); }
	node<T>& operator=(node&& copy) noexcept;

	virtual ~node() = default;

	T& get_data() noexcept { return data_; }
	T get_data() const { return data_; }
	void set_data(const T& data) { data_ = data; }

protected:
	T data_;
};

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
node<T>& node<T>::operator=(node&& copy) noexcept
{
	if (this != copy)
	{	
		data_ = copy.get_data();
	}
	return *this;
}

#endif
