#ifndef STATIC_QUEUE_HPP
#define STATIC_QUEUE_HPP
#include "i_queue.hpp"
#include "array.hpp"

template <class T>
class static_queue : public i_queue<T>
{
public:
	static_queue() = default;
	explicit static_queue(size_t size);
	static_queue(const static_queue& copy);
	static_queue(static_queue&& copy) noexcept;
	static_queue& operator=(const static_queue& rhs);
	static_queue& operator=(static_queue&& rhs) noexcept;

	void enqueue(T data) override;
	T dequeue() override;
	T& front() override;
	bool full() const noexcept;
	void clear() noexcept override;

	size_t size() const noexcept override;
	bool empty() const noexcept override;

	T get_queue_element(T data);

	~static_queue() = default;

private:
	dynamic_array<T> queue_{};
	int f_ = 0;
	int r_ = 0;
};

template <class T>
static_queue<T>::static_queue(size_t size)
{
	try
	{
		queue_.set_length(size);
		this->size_ = size;
	}
	catch (const std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}
}

template <class T>
static_queue<T>::static_queue(const static_queue& copy)
{
	*this = copy;
}

template <class T>
static_queue<T>::static_queue(static_queue&& copy) noexcept
{
	*this = std::move(copy);
}

template <class T>
static_queue<T>& static_queue<T>::operator=(const static_queue& rhs)
{
	if (this != &rhs)
	{
		this->size_ = rhs.size_;
		queue_ = rhs.queue_;
		f_ = rhs.f_;
		r_ = rhs.r_;
	}
	return *this;
}

template <class T>
static_queue<T>& static_queue<T>::operator=(static_queue&& rhs) noexcept
{
	if (this != &rhs)
	{
		this->size_ = rhs->size_;
		queue_ = rhs.queue_;
		f_ = rhs->f_;
		r_ = rhs->r_;
	}
	return *this;
}

template <class T>
void static_queue<T>::enqueue(T data)
{
	if (this->full())
	{
		
	}
	else if(this->empty())
	{
		queue_[f_] = data;
		r_ = 1;
	}
	else
	{
		queue_[r_] = data;
		r_ = r_ + 1 % this->size_;
	}
}

template <class T>
T static_queue<T>::dequeue()
{
	if(!this->empty())
	{
	
	}
	auto data = queue_[f_];
	f_ = f_ + 1 % this->size_;
	return data;
}

template <class T>
T& static_queue<T>::front()
{
	return queue_[f_];
}

template <class T>
bool static_queue<T>::full() const noexcept
{
	return this->size_ == this->size();
}

template <class T>
void static_queue<T>::clear() noexcept
{
	for (auto i{0}; i < this->size_; ++i)
	{
		queue_[i] = 0;
	}
	f_ = 0;
	r_ = 0;
}

template <class T>
size_t static_queue<T>::size() const noexcept
{
	const auto number_of_elements = (this->size_ - f_ + r_) % this->size_;
	if (this->size_ == r_ && (r_ - f_) == this->size_)
	{
		return this->size_;
	}
	return number_of_elements;
}

template <class T>
bool static_queue<T>::empty() const noexcept
{
	if (f_ == r_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
T static_queue<T>::get_queue_element(T data)
{
	return queue_[data];
}


#endif // STATIC_QUEUE_HPP
