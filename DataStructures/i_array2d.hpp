#ifndef I_ARRAY2D_HPP
#define I_ARRAY2D_HPP

template<class T>
class row;

template<class T>
class i_array2d
{

public:
	virtual ~i_array2d() = default;
	virtual T select(int row, int column) const = 0;
	virtual T& select(int row, int column) = 0;
	//virtual row<T> operator[](int row) const = 0;
	//virtual row<T> operator[](int row) = 0;
	virtual operator bool() = 0;
	virtual size_t get_rows() = 0;
	virtual size_t get_columns() = 0;
	virtual void set_rows(size_t rows) = 0;
	virtual void set_columns(size_t columns) = 0;
};



#endif