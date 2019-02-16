#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "array.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(array_test)
	{
	public:
		//TEST_METHOD_INITIALIZE(test_init)
		//{
		//	freopen("TestLog.txt", "a+", stdout);
		//}

		TEST_METHOD(array_get_length_test)
		{
			// Arrange
			crt_check_memory check;
			dynamic_array<int> arr(5);

			// Act
			const auto result = arr.get_length();
			const size_t expect {5};
			
			// Assert
			Assert::AreEqual(expect, result);
		}

		TEST_METHOD(array_get_start_index_default_test)
		{
			// Arrange
			crt_check_memory check;
			dynamic_array<int> arr(5);

			// Act
			const auto result = arr.get_start_index();
			const int expect{ 0 };

			// Assert
			Assert::AreEqual(expect, result);
		}

		TEST_METHOD(array_get_start_index_entered_test)
		{
			// Arrange
			crt_check_memory check;
			dynamic_array<int> arr(5, -1);

			// Act
			const auto result = arr.get_start_index();
			const int expect{ -1 };

			// Assert
			Assert::AreEqual(expect, result);
		}

		TEST_METHOD(array_set_length_test)
		{
			// Arrange
			crt_check_memory check;
			dynamic_array<int> arr(5);

			// Act
			arr.set_length(100);
			const auto result = arr.get_length();
			const size_t expect = 100;

			// Assert
			Assert::AreEqual(expect, result);
		}


		TEST_METHOD(array_bracket_operator_default_start_index_test)
		{
			// Arrange
			crt_check_memory check;
			
				dynamic_array<int> arr(5);

			// Act
			for (auto i = 0; i < arr.get_length(); ++i)
			{
				arr[i] = i;
			}

			// Assert
			for (auto i = 0; i < arr.get_length(); ++i)
			{
				Assert::AreEqual(i, arr[i]);
			}
			
		}

		TEST_METHOD(array_bracket_operator_positive_start_index_test)
		{
			// Arrange
			crt_check_memory check;

			dynamic_array<int> arr(5,1);

			// Act
			for (auto i = 1; i < 6; ++i)
			{
				arr[i] = i;
			}

			// Assert
			for (auto i = 1; i < 5; ++i)
			{
				Assert::AreEqual(i, arr[i]);
			}
		}

		TEST_METHOD(array_bracket_operator_negative_start_index_test)
		{
			// Arrange
			crt_check_memory check;

			dynamic_array<int> arr(5, -3);

			// Act
			for (auto i = -3; i < 2; ++i)
			{
				arr[i] = i;
			}

			// Assert
			for (auto i = -3; i < 2; ++i)
			{
				Assert::AreEqual(i, arr[i]);
			}
		}

		TEST_METHOD(array_copy_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			const dynamic_array<int> arr(5, 1);


			// Act
			const dynamic_array<int> arr2(arr);

			// Assert
		    Assert::AreEqual(arr.get_length(), arr2.get_length() );
		    Assert::AreEqual(arr.get_start_index(), arr2.get_start_index());
			
		}

		TEST_METHOD(array_constructor_with_array_passed_in_test)
		{
			// Arrange
			crt_check_memory check;
			int c_array[5]{ 0, 1, 2, 3, 4 };

			// Act
			const dynamic_array<int> arr(c_array, 5);

			// Assert
			for (auto i = 0; i < arr.get_length(); ++i)
			{
				Assert::AreEqual(c_array[i], arr[i]);
			}

		}


	};
}