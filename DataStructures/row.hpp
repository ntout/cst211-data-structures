#ifndef ROW_HPP
#define ROW_HPP

#include "adt_exception.hpp"
#include "i_row.hpp"

class i_array2d;

template<class T>
class row : public i_row<T>
{

public:
	row(const i_array2d<T>& array, const int& row);

	~row() = default;
	T& operator[](const int& column) override;
	T operator[](const int& column) const override;

private:
	i_array2d<T> array2d;
	int row_index = 0;
};

template <class T>
T& row<T>::operator[](const int& column)
{
	if (column < 0 || column > array2d.storage_.get_length())
	{
		throw(adt_exception("index is out of bounds"));
	}
	return array2d.storage_[column];
}


#endif
