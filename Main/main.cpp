#include "CrtDbg.h"
#include <iostream>
#include "array.hpp"

using std::cin;

#define _CRTDBG_MAP_ALLOC

int main()
{
	{
		{
			dynamic_array<int> arr(5, -5);


			// Act
			for (auto i = 0; i < arr.get_length(); ++i)
			{
				arr[i] = i;
			}

			// Assert
			for (auto i = 0; i < arr.get_length(); ++i)
			{
				//Assert::AreEqual(i, arr[i]);
			}
		}
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	cin.get();
    return 0;
}