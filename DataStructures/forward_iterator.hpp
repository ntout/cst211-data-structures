#ifndef FORWARDITERATOR_HPP
#define FORWARDITERATOR_HPP

#include "list_iterator.hpp"

template <class T>
class forward_iterator : public list_iterator<T>
{
public:
	forward_iterator() = default;
	~forward_iterator() = default;

	forward_iterator(const forward_iterator& copy) noexcept;
	forward_iterator& operator=(const forward_iterator& rhs) noexcept;

	forward_iterator(list_node<T>* const copy) noexcept;
	forward_iterator& operator=(list_node<T>* const rhs) noexcept override;

	forward_iterator(forward_iterator&& copy) noexcept;
	forward_iterator& operator=(forward_iterator&& rhs) noexcept;

	void move_next() override; //if next next is nullptr
	void reset() noexcept override;
	forward_iterator& operator++();
	const forward_iterator operator++(int);
};

template <class T>
forward_iterator<T>& forward_iterator<T>::operator++()
{
	auto temp = *this;
	move_next();
	return temp;
}

#endif
