#ifndef SORT_METHOD_HPP
#define SORT_METHOD_HPP

namespace sort_method {
	template <class T>
	void selection(T& arr, const int length)
	{
		for (auto i = length - 1; i >= 1; --i)
		{
			auto index = i;
			for (auto j = 0; j < i; j++)
			{
				if (arr[j] > arr[index])
					index = j;
			}
			int temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}


	template<class T>
	void brute_force_bubble(T a, const int length) 
	{
		for (int i = 1; i < length; i++) 
		{
			for (int j = 0; j < length - i; j++) 
			{
				if (a[j] > a[j + 1]) 
				{
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}

	template<class T>
	void flagged_bubble(T a, const int size) 
	{
		for (int i = 1; i < size; i++) 
		{
			bool isSorted = true; // isSorted = true if a[] is sorted
			for (int j = 0; j < size - i; j++) 
			{
				if (a[j] > a[j + 1]) 
				{ // the larger item bubbles up
					int temp = a[j]; // and isSorted is set to false,
					a[j] = a[j + 1]; // i.e. the data was not sorted
					a[j + 1] = temp;
					isSorted = false;
				}
			}
			if (isSorted) return; // Why?
		}
	}

	template<class T>
	void insertion(T a, const int length) 
	{
		for (int i = 1; i < length; i++) 
		{
			// a[i] is the next data to insert
			int next = a[i];
			// Scan backwards to find a place.
			int j;
			for (j = i - 1; j >= 0 && a[j] > next; j--)
				a[j + 1] = a[j];
			// Now insert the value next after index j at the end of loop
			a[j + 1] = next;
		}
	}



}




#endif
