#ifndef DYNAMIC_STACK_HPP
#define DYNAMIC_STACK_HPP

#include "i_stack.hpp"
#include "linked_list.hpp"
#include "adt_exception.hpp"

template <class T>
class dynamic_stack : public i_stack<T>
{
public:
	dynamic_stack() = default;
	dynamic_stack(const dynamic_stack& copy);
	dynamic_stack(dynamic_stack&& copy) noexcept;
	dynamic_stack& operator=(const dynamic_stack& rhs);
	dynamic_stack& operator=(dynamic_stack&& rhs) noexcept;
	~dynamic_stack() = default;

	T pop() override;
	T peek() override;
	void push(T data) override;
	void clear() noexcept override;
private:
	linked_list<T> stack_{};
};

template <class T>
dynamic_stack<T>::dynamic_stack(const dynamic_stack& copy)
{
	*this = copy;
}

template <class T>
dynamic_stack<T>::dynamic_stack(dynamic_stack&& copy) noexcept
{
	*this = std::move(copy);
}

template <class T>
dynamic_stack<T>& dynamic_stack<T>::operator=(const dynamic_stack& rhs)
{
	if (this != &rhs)
	{
		this->stack_ = rhs->stack_;
	}
	return *this;
}

template <class T>
dynamic_stack<T>& dynamic_stack<T>::operator=(dynamic_stack&& rhs) noexcept
{
	if (this != &rhs)
	{
		this->stack_ = rhs->stack_;
	}
	return *this;
}

template <class T>
T dynamic_stack<T>::pop()
{
	T data = stack_.last();
	stack_.remove_last();
	return data;
}

template <class T>
T dynamic_stack<T>::peek()
{
	return stack_.last();
}

template <class T>
void dynamic_stack<T>::push(T data)
{
	stack_.append(data);
}

template <class T>
void dynamic_stack<T>::clear() noexcept
{
	stack_.clear();
}


#endif // DYNAMIC_STACK_HPP
