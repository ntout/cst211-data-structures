#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "linked_list.hpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(linked_list_tests)
	{
	public:

		TEST_METHOD(ll_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			try
			{
				linked_list<int> list;

				Assert::IsTrue(list.is_empty());
				Assert::IsNull(list.get_head());

			}
			catch (adt_exception adt_exception)
			{
				Assert::Fail(adt_exception.adt_what());
			}
			
		}

		TEST_METHOD(LinkedListCopyConstructor)
		{
			crt_check_memory check;

			linked_list<int> a_list;
			a_list.append(5);

			linked_list<int> b_list(a_list);
			
			Assert::IsFalse(b_list.is_empty());
			Assert::AreEqual(5, b_list.first());



		}

	};
}