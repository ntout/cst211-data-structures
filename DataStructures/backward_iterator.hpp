#ifndef BACKWARDITERATOR_HPP
#define BACKWARDITERATOR_HPP

#include "list_iterator.hpp"

template <class T>
class backward_iterator : public list_iterator<T>
{
public:
	backward_iterator() = default;
	~backward_iterator() = default;
	backward_iterator(const backward_iterator& copy) noexcept;
	backward_iterator& operator=(const backward_iterator& rhs) noexcept;

	backward_iterator(list_node<T>* const copy) noexcept; 
	backward_iterator& operator=(list_node<T>* const rhs) noexcept override;
	
	backward_iterator(backward_iterator&& copy) noexcept;
	backward_iterator& operator=(backward_iterator&& rhs) noexcept;
	
	void move_next() override;
	void reset() noexcept override;
	backward_iterator& operator++();
	const backward_iterator operator++(int);
};

template <class T>
void backward_iterator<T>::reset() noexcept
{
	//auto current = node_
	//while current != nullptr
	//	current = current->next
	//
}

template <class T>
backward_iterator<T>& backward_iterator<T>::operator++()
{
	//move_next()
	//return *this
}

#endif
