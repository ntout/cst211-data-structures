#ifndef I_ROW_HPP
#define I_ROW_HPP


template<class T>
class i_row
{
	virtual ~i_row() = default;
	virtual T& operator[](const int& column) = 0;
	virtual T operator[](const int& column) const = 0;
};

#endif