#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "pair.hpp"
#include <xlocmon>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(pair_test)
	{
	public:
		static pair<int,int> get_pair()
		{
			return pair<int, int>(1, 1);
		}

		TEST_METHOD(pair_get_first_test)
		{
			// Arrange
			crt_check_memory check;
			pair<int, int> pair1(5, 5);

			// Act
			const auto result = pair1.get_first();

			// Assert
			Assert::AreEqual(5, result);
		}

		TEST_METHOD(pair_get_second_test)
		{
			// Arrange
			crt_check_memory check;
			pair<int, int> pair1(5, 5);

			// Act
			const auto result = pair1.get_second();

			// Assert
			Assert::AreEqual(5, result);
		}

		TEST_METHOD(pair_copy_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			const pair<int, int> pair1(5, 5);

			// Act
			auto pair2 = pair<int, int>(pair1);


			// Assert
			Assert::AreEqual(pair1.get_first(), pair2.get_first());
			Assert::AreEqual(pair1.get_second(), pair2.get_second());
		}

		TEST_METHOD(pair_move_constructor_test)
		{
			// Arrange
			crt_check_memory check;

			// Act
			auto pair2 = std::move(get_pair());

			// Assert
			Assert::AreEqual(1, pair2.get_first());
			Assert::AreEqual(1, pair2.get_second());
		}

		TEST_METHOD(pair_equality_operator_test)
		{
			// Arrange
			crt_check_memory check;
			pair<int, int> pair1(5, 5);
			pair<int, int> pair2(5, 5);

			// Act
			const auto result = pair1 == pair2;

			// Assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(pair_const_equality_operator_test)
		{
			// Arrange
			crt_check_memory check;
			const pair<int, int> pair1(5, 5);
			const pair<int, int> pair2(5, 5);

			// Act
			const auto result = pair1 == pair2;

			// Assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(pair_set_first_test)
		{
			// Arrange
			crt_check_memory check;
			pair<int, int> pair1(5, 5);

			// Act
			pair1.set_first(1);
	
			// Assert
			Assert::AreEqual(1, pair1.get_first());
		}

		TEST_METHOD(pair_set_second_test)
		{
			// Arrange
			crt_check_memory check;
			pair<int, int> pair1(5, 5);

			// Act
			pair1.set_second(1);

			// Assert
			Assert::AreEqual(1, pair1.get_second());
		}

		TEST_METHOD(pair_ostream_operator_test)
		{
			// Arrange
			crt_check_memory check;
			const pair<int, int> pair1(5, 5);
			const std::string expected = "5 5";

			// Act
			std::stringstream out;
			out << pair1;
			const auto result = out.str();
			
			// Assert
			Assert::AreEqual(expected, result);
		}
	};	
}