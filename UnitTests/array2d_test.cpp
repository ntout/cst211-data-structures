#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "array2d.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(array2d_test)
	{
	public:

		TEST_METHOD(arrar2d_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			
			// Act
			array2d<int> arr2d(2, 2);
			const size_t expected = 2;

			// Assert
			Assert::AreEqual(expected, arr2d.get_columns());

		}

		TEST_METHOD(arrar2d_copy_test)
		{
			// Arrange
			crt_check_memory check;

			// Act
			array2d<int> arr1(2, 2);
			array2d<int> arr2 = arr1;


			// Assert
			Assert::AreEqual(arr1.get_columns(), arr2.get_columns());

		}

	};
}