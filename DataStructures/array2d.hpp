#ifndef ARRAY2D_HPP
#define ARRAY2D_HPP
#include "adt_exception.hpp"
#include "i_array2d.hpp"
#include "array.hpp"


template<class T>
class array2d : public i_array2d<T>
{

public:
	T select(int row, int column) const override;
	T& select(int row, int column) override;
	//row<T> operator[](int row) const override;
	//row<T> operator[](int row) override;
	operator bool() override;

	size_t get_rows() override;
	size_t get_columns() override;
	void set_rows(size_t rows) override;
	void set_columns(size_t columns) override;

	explicit array2d(const size_t rows, const size_t columns);
	array2d(const array2d& copy);
	~array2d() = default;
	array2d<T>& operator=(const array2d& rhs);
	array2d(array2d<T>&& copy) noexcept;
	array2d<T>& operator=(array2d<T>&& rhs) noexcept;

private:
	dynamic_array<T> storage_;
	size_t rows_ = 0;
	size_t columns_ = 0;
};

template <class T>
T array2d<T>::select(int row, int column) const
{

	int index = (rows_ * row) + column;
	if (index < 0 || index >= storage_.get_length())
	{
		throw(adt_exception("index is out of bounds"));
	}
	return storage_[index];
}

template <class T>
T& array2d<T>::select(int row, int column)
{
	int index = (rows_ * row) + column;
	if (index < 0 || index >= storage_.get_length())
	{
		throw(adt_exception("index is out of bounds"));
	}
	return storage_[index];
}




template  <class T>
array2d<T>::operator bool()
{
	return (*this != 0);
}

template <class T>
size_t array2d<T>::get_rows()
{
	return rows_;
}

template <class T>
size_t array2d<T>::get_columns()
{
	return columns_;
}

template <class T>
void array2d<T>::set_rows(size_t rows)
{
	rows_ = rows;
}

template <class T>
void array2d<T>::set_columns(size_t columns)
{
	columns_ = columns;
}

template <class T>
array2d<T>::array2d(const size_t rows, const size_t columns)
{
	try
	{
		rows_ = rows;
		columns_ = columns;
		storage_.set_length(rows * columns);
		
	}
	catch (const std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}
}

template <class T>
array2d<T>::array2d(const array2d& copy)
{
	*this = copy;
}

template <class T>
array2d<T>& array2d<T>::operator=(const array2d& rhs)
{
	if (this != &rhs)
	{
		
		rows_ = rhs.rows_;
		columns_ = rhs.columns_;
		const auto length = rows_ * columns_;
		storage_.set_length(length);

		for (auto i = 0; i < length; ++i)
		{
			storage_[i] = rhs.storage_[i];
		}
	}
	return *this;
}

template <class T>
array2d<T>::array2d(array2d<T>&& copy) noexcept
{
	*this = std::move(copy);
}

template <class T>
array2d<T>& array2d<T>::operator=(array2d<T>&& rhs) noexcept
{
	if (this != &rhs)
	{
		delete[] storage_.storage_;

		rows_ = rhs.rows_;
		columns_ = rhs.columns_;
		const auto length = rows_ * columns_;
		storage_ = new dynamic_array<T>[length];

		for (auto i = 0; i < length; ++i)
		{
			storage_[i] = rhs.storage_[i];
		}
	}
	return *this;
}


#endif
