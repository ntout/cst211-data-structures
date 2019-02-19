#ifndef I_STACK_HPP
#define I_STACK_HPP

template <class T>
class i_stack
{
public:
	virtual ~i_stack() = default;
	virtual T pop() = 0;
	virtual T peek() = 0;
	virtual void push(T data) = 0;
	virtual bool empty() const noexcept = 0;
	virtual size_t size() const noexcept = 0;
	virtual void clear() noexcept = 0;
protected:
	size_t size_ = 0;
};


#endif
