#ifndef STATIC_STACK_HPP
#define STATIC_STACK_HPP
#include "i_stack.hpp"
#include "array.hpp"
#include "adt_exception.hpp"

template <class T>
class static_stack : public i_stack<T>
{
public:
	static_stack() = default;
	explicit static_stack(const size_t& size);
	static_stack(const static_stack& copy);
	static_stack(static_stack&& copy) noexcept;
	static_stack& operator=(const static_stack& rhs);
	static_stack& operator=(static_stack&& rhs) noexcept;
	~static_stack() = default;

	size_t size() const noexcept override;
	bool empty() const noexcept override;
	T pop() override;
	T peek() override;
	void push(T data) override;
	bool full() const noexcept;
	void clear() noexcept override;

	size_t get_top() const;

private:
	dynamic_array<T> stack_{};
	size_t top_{};
};

template <class T>
static_stack<T>::static_stack(const size_t& size)
{
	try
	{
		stack_.set_length(size);
		this->size_ = size;
		top_ = size + 1;
	}
	catch (const std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}
}

template <class T>
static_stack<T>::static_stack(const static_stack& copy)
{
	*this = copy;
}

template <class T>
static_stack<T>::static_stack(static_stack&& copy) noexcept
{
	*this = std::move(copy);
}

template <class T>
static_stack<T>& static_stack<T>::operator=(const static_stack& rhs)
{
	if (this != &rhs)
	{
		this.stack_ = rhs.stack_;
		this->size_ = rhs->size_;
	}
	return *this;
}

template <class T>
static_stack<T>& static_stack<T>::operator=(static_stack&& rhs) noexcept
{
	if (this != &rhs)
	{
		this.stack_ = rhs.stack_;
		this->size_ = rhs->size_;
	}
	return *this;
}

template <class T>
size_t static_stack<T>::size() const noexcept
{
	if(top_ != this->size_ + 1)
	{
		return top_ + 1;
	}
	return 0;
}

template <class T>
bool static_stack<T>::empty() const noexcept
{
	return top_ == this->size_ + 1;
}

template <class T>
T static_stack<T>::pop()
{
	if(this->empty())
	{
		//throw StackEmptyExcpetion;
	}
	else
	{
		top_ -= 1;
	}
	return stack_[top_ + 1];
}

template <class T>
T static_stack<T>::peek()
{
	return stack_[top_];
}


template <class T>
void static_stack<T>::push(T data)
{
	if(this->size() == stack_.get_length())
	{
		//throw stack full exception
	}
	else if(this->empty())
	{
		top_ = 0;
		stack_[top_] = data;
	}
	else
	{
		top_ += 1;
		stack_[top_] = data;
	}
}

template <class T>
bool static_stack<T>::full() const noexcept
{
	return top_ + 1 == this->size_;
}


template <class T>
void static_stack<T>::clear() noexcept
{
	for(auto i{0}; i < this->size_; ++i)
	{
		stack_[i] = 0;
		top_ = this->size_ + 1;
	}
}

template <class T>
size_t static_stack<T>::get_top() const
{
	return top_;
}

#endif // STATIC_STACK_HPP
