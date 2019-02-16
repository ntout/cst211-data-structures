#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "list_node.hpp"
#include "adt_exception.hpp"
#include "linked_list.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(list_node_test)
	{
	public:

		TEST_METHOD(list_node_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			list_node<int> ln(5);

			// Act
			const auto result = ln.get_data();

			// Assert
			Assert::AreEqual(5, result);
		}

		TEST_METHOD(list_node_copy_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			list_node<int> ln(5);

			// Act
			list_node<int> ln2(ln);

			// Assert
			Assert::AreEqual(ln.get_data(), ln2.get_data());
		}

		TEST_METHOD(list_node_setter_test)
		{
			// Arrange
			crt_check_memory check;
			list_node<int> ln1(1);
			list_node<int> ln2(2);
			list_node<int> ln3(3);


			// Act
			ln2.set_previous(&ln1);
			ln2.set_next(&ln3);

			// Assert
			Assert::AreEqual(ln1.get_data(), ln2.get_previous()->get_data());
			Assert::AreEqual(ln3.get_data(), ln2.get_next()->get_data());
		}

	};
}