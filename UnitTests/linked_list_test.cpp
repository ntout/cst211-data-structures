#include "stdafx.h"
#include "CppUnitTest.h"

#include "adt_exception.hpp"
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
			linked_list<int> listy;

			// Act
			
			

			//Assert
			
		}

		TEST_METHOD(ll_append_test)
		{
			// Arrange
			crt_check_memory check;
			linked_list<int> listy;

			// Act
			listy.append(1);
			listy.append(2);
			listy.append(3);
			
			const int len = listy.get_length();


			//Assert
			Assert::AreEqual(3,len);
			Assert::AreEqual(1, listy.first());
			Assert::AreEqual(3, listy.last());
		}

		TEST_METHOD(ll_prepend_test)
		{
			// Arrange
			crt_check_memory check;
			linked_list<int> listy;

			// Act
			for (auto i{0}; i < 10; ++i)
			{
				if(i % 2 == 0)
				{
					listy.append(i);
				}
				else
				{
					listy.prepend(i);
				}
			}

			const int len = listy.get_length();

			//Assert
			Assert::AreEqual(10, len);
			Assert::AreEqual(9, listy.first());
			Assert::AreEqual(8, listy.last());

			auto current = listy.get_head();
			while(current != listy.get_tail())
			{
				auto next = current->get_next();
				Assert::AreEqual(current->get_data(), next->get_previous()->get_data());
				current = next;
			}
		}

		TEST_METHOD(ll_remove_last_test)
		{
			// Arrange
			crt_check_memory check;
			linked_list<int> listy;

			// Act
			listy.append(1);
			listy.append(2);
			listy.append(3);

			listy.remove_last();

			const int len = listy.get_length();


			//Assert
			Assert::AreEqual(2, len);
			Assert::AreEqual(2, listy.last());
		}

		TEST_METHOD(ll_remove_first_test)
		{
			// Arrange
			crt_check_memory check;
			linked_list<int> listy;

			// Act
			listy.append(1);
			listy.append(2);
			listy.append(3);

			listy.remove_first();

			const int len = listy.get_length();

			//Assert
			Assert::AreEqual(2, len);
			Assert::AreEqual(2, listy.first());
			Assert::AreEqual(3, listy.last());
		}

		TEST_METHOD(ll_extract_test)
		{
			// Arrange
			crt_check_memory check;
			linked_list<int> listy;

			// Act
			for(auto i{0}; i < 10; ++i)
			{
				listy.append(i);
			}

			listy.extract(0);
			listy.extract(9);
			listy.extract(4);
			const int len = listy.get_length();

			//Assert
			Assert::AreEqual(7, len);
			Assert::AreEqual(1, listy.first());
			Assert::AreEqual(8, listy.last());
		}

		TEST_METHOD(ll_insert_before_test)
		{
			// Arrange
			crt_check_memory check;
			linked_list<int> listy;

			// Act
			for (auto i{ 2 }; i < 10; ++i)
			{
				listy.append(i);
			}
			listy.insert_before(4, 2);

			const int len = listy.get_length();

			//Assert
			Assert::AreEqual(9, len);
			Assert::AreEqual(4, listy.first());
			Assert::AreEqual(9, listy.last());

			auto current = listy.get_head();
			while (current != listy.get_tail())
			{
				auto next = current->get_next();
				Assert::AreEqual(current->get_data(), next->get_previous()->get_data());
				current = next;
			}
		}
		
	/**************TEST PROVIDED TO US*********************/

		TEST_METHOD(LinkedListDefaultConstructor)
		{
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
			try
			{
				linked_list<int> a_list;
				a_list.append(5);

				linked_list<int> b_list(a_list);

				Assert::IsFalse(b_list.is_empty());
				Assert::AreEqual(5, b_list.first());

			}
			catch (adt_exception adt_exception)
			{
				Assert::Fail(adt_exception.adt_what());
			}
		}
	};
}