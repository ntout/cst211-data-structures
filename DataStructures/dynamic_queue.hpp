#ifndef DYNAMIC_QUEUE_HPP
#define DYNAMIC_QUEUE_HPP

#include "i_queue.hpp"
#include "linked_list.hpp"

template <class T>
class dynamic_queue : public i_queue<T>
{
public:
	dynamic_queue() = default;
	dynamic_queue(const dynamic_queue& copy);
	dynamic_queue& operator=(const dynamic_queue& rhs);
	dynamic_queue(dynamic_queue&& copy) noexcept;
	dynamic_queue& operator=(dynamic_queue&& rhs) noexcept;
	~dynamic_queue() = default;

	void enqueue(T data) override;
	T dequeue() override;
	T& front() override;
	void clear() noexcept override;
	size_t size() const noexcept override;
	bool empty() const noexcept override;

private:
	linked_list<T> queue_{};
};


template <class T>
dynamic_queue<T>::dynamic_queue(const dynamic_queue& copy)
{
	*this = copy;
}

template <class T>
dynamic_queue<T>& dynamic_queue<T>::operator=(const dynamic_queue& rhs)
{
	if (this != &rhs)
	{
		queue_ = rhs.queue_;
	}

	return *this;
}

template <class T>
dynamic_queue<T>::dynamic_queue(dynamic_queue&& copy) noexcept
{
	*this = std::move(copy);
}

template <class T>
dynamic_queue<T>& dynamic_queue<T>::operator=(dynamic_queue&& rhs) noexcept
{
	if (this != &rhs)
	{
		queue_ = rhs.queue_;
	}

	return *this;
}

template <class T>
void dynamic_queue<T>::enqueue(T data)
{
	queue_.append(data);
}

template <class T>
T dynamic_queue<T>::dequeue()
{
	auto data = queue_.head_->get_data();
	queue_.prepend();
	return data;
}

template <class T>
T& dynamic_queue<T>::front()
{
	return queue_.head_->get_data();
}

template <class T>
void dynamic_queue<T>::clear() noexcept
{
	queue_.clear();
}

template <class T>
size_t dynamic_queue<T>::size() const noexcept
{
	return queue_.get_length();
}

template <class T>
bool dynamic_queue<T>::empty() const noexcept
{
	return queue_.is_empty();
}

#endif // DYNAMIC_QUEUE_HPP
