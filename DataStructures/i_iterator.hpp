#ifndef IITERATOR_HPP
#define IITERATOR_HPP

template <class T>
class i_iterator
{
public:
	virtual ~i_iterator() = default;
	virtual void move_next() = 0;
	virtual void reset() noexcept = 0;
	virtual bool is_done() const noexcept = 0;
	virtual T& get_current() = 0;
	virtual T get_current() const = 0;
	explicit virtual operator void*() const noexcept = 0;
};
#endif