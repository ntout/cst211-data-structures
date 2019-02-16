#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "adt_exception.hpp"
#include "iostream"

template <class T>
class dynamic_array final
{
public:
	explicit dynamic_array();
	~dynamic_array();
	explicit dynamic_array(size_t length, int start_index = 0);
	explicit dynamic_array(const dynamic_array<T>& array) noexcept(false);
	explicit dynamic_array(const T array[], size_t size);
	dynamic_array<T>& operator=(const dynamic_array<T>& rhs);
	explicit dynamic_array(dynamic_array<T>&& array) noexcept;
	dynamic_array<T>& operator=(dynamic_array<T>&& rhs) noexcept;
	T & operator[](int index) noexcept(false);
	T operator[](int index) const noexcept(false);
	operator bool();

	int get_start_index() const;
	size_t get_length() const;

	void set_start_index(int start_index);
	void set_length(size_t length);

private:
	T* storage_ = nullptr;
	size_t length_ = 0;
	int start_index_ = 0;
};

template <class T>
dynamic_array<T>::dynamic_array()
{
}

template <class T>
dynamic_array<T>::~dynamic_array()
{
	 delete []storage_;
}

template <class T>
dynamic_array<T>::dynamic_array(const size_t length, const int start_index)
{	
	try 
	{
		length_ = length;
		start_index_ = start_index;
		storage_ = new T[length];
		
	}
	catch (const std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}

}

template <class T>
dynamic_array<T>::dynamic_array(const dynamic_array<T>& array) noexcept(false)
{
	*this = array;
}

template <class T>
dynamic_array<T>::dynamic_array(const T array[], size_t size)
{
	try
	{
		start_index_ = 0;
		length_ = size;
		storage_ = new T[size];
	}
	catch (const std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}

	for (auto i = 0; i < size; ++i)
	{
		storage_[i] = array[i];
	}
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array<T>& rhs)
{
	if (this != &rhs)
	{
		delete[] storage_;

		length_ = rhs.length_;
		start_index_ = rhs.start_index_;
		storage_ = new T[length_];

		for (auto i =0; i < length_; ++i)
		{
			storage_[i] = rhs.storage_[i];
		}
		
	}
	return *this;
}

template <class T>
dynamic_array<T>::dynamic_array(dynamic_array<T>&& array) noexcept
{
	*this = std::move(array);
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(dynamic_array<T>&& rhs) noexcept
{
	if (this != &rhs) {

		delete[] storage_;

		length_ = rhs.length_;
		start_index_ = rhs.start_index_;
		storage_ = rhs.storage_;

		rhs.storage_ = nullptr;

		//std::copy(rhs.storage_, rhs.storage_ + length_, storage_);

		{
			return *this;
		}
	}
}

template <class T>
T& dynamic_array<T>::operator[](int index)
{
	const auto actual_index = index - start_index_;
	if ( actual_index < 0 || actual_index > length_)
	{
		throw(adt_exception("index is out of bounds"));
	}
	return storage_[actual_index];
}

template <class T>
T dynamic_array<T>::operator[](int index) const
{
	const auto actual_index = index - start_index_;
	if (actual_index < 0 || actual_index >= length_)
	{
		throw(adt_exception("index is out of bounds"));
	}
	return storage_[actual_index];
}

template <class T>
dynamic_array<T>::operator bool()
{
	return (*this != 0);
}

template <class T>
int dynamic_array<T>::get_start_index() const
{
	return start_index_;
}

template <class T>
size_t dynamic_array<T>::get_length() const
{
	return length_;
}

template <class T>
void dynamic_array<T>::set_start_index(int start_index)
{
	start_index_ = start_index;
}

template <class T>
void dynamic_array<T>::set_length(size_t length)
{
	try
	{
		T* temp = new T[length];
		const auto copy_length = length_ < length ? length_ : length;

		for (int i = 0; i < copy_length; ++i)
		{
			temp[i] = storage_[i];
		}

		delete[] storage_;

		storage_ = temp;

		length_ = length;
	}
	catch (const std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}

}


#endif
