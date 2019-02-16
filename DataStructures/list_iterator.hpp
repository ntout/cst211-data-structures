#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include "adt_exception.hpp"
#include "i_iterator.hpp"
#include "list_node.hpp"

template <class T>
class list_iterator : public i_iterator<T>
{
public:
	list_iterator() = default;
	list_iterator(const list_iterator& copy) noexcept;

	list_iterator(list_node<T>* const copy) noexcept;
	
	list_iterator& operator=(const list_iterator& rhs) noexcept;
	virtual list_iterator& operator=(list_node<T>* const rhs) noexcept;

	list_iterator(list_iterator&& copy) noexcept;
	list_iterator& operator=(list_iterator&& rhs) noexcept;

	T& operator*();
	T operator*() const;
	T& get_current() override;
	T get_current() const override;
	T* operator->();
	T* operator->() const;
	bool is_done() const noexcept override;
	operator void*() const noexcept override;

	virtual ~list_iterator() = default;


protected:
	list_node<T>* node_ {nullptr};
	bool done_ {true};
};

#endif 