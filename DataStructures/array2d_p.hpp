#ifndef ARRAY2D_P_HPP
#define ARRAY2D_P_HPP
#include "adt_exception.hpp"
#include "i_array2d.hpp"



template<class T>
class array2d_p : public i_array2d<T>
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

	
	explicit array2d_p(const size_t rows, const size_t columns);
	~array2d_p();
	array2d_p(const array2d_p& copy);
	array2d_p(array2d_p<T>&& copy);
	array2d_p<T>& operator=(const array2d_p& rhs);
	array2d_p<T>& operator=(array2d_p<T>&& rhs);
private:
	T** storage_ = nullptr;
	size_t rows_ = 0;
	size_t columns_ = 0;

};

#endif