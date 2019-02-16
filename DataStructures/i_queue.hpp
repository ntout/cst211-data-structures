#ifndef I_QUEUE_HPP
#define I_QUEUE_HPP
#include "adt_exception.hpp"

template <class T>
class i_queue
{
public:
	virtual ~i_queue() = default;
	virtual void enqueue(T data) = 0;
	virtual T dequeue() = 0;
	virtual T& front() = 0;
	virtual void clear() noexcept = 0;

	virtual size_t size() const noexcept = 0;
	virtual bool empty() const noexcept = 0;

protected:
	size_t size_ = 0;

};

#endif // I_QUEUE_HPP
