#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(node_tests)
	{
	public:

		TEST_METHOD(node_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			node<int> n(5);

			// Act
			const auto result = n.get_data();

			// Assert
			Assert::AreEqual(5, result);
		}

		TEST_METHOD(node_set_data_test)
		{
			// Arrange
			crt_check_memory check;
			node<int> n(5);

			// Act
			const int data = 2;
			n.set_data(data);
			const auto result = n.get_data();

			// Assert
			Assert::AreEqual(data, result);
		}

		TEST_METHOD(node_copy_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			node<int> n(5);
			

			// Act
			node<int> n2(n);

			// Assert
			Assert::AreEqual(n.get_data(), n2.get_data());
		}

		TEST_METHOD(node_equal_operator_test)
		{
			// Arrange
			crt_check_memory check;
			node<int> n(5);


			// Act
			node<int> n2 = n;

			// Assert
			Assert::AreEqual(n.get_data(), n2.get_data());
		}

	};
}