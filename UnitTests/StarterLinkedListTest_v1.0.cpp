#include "stdafx.h"
//#include "CppUnitTest.h"
//#include "crt_check_memory.hpp"
//#include "linked_list.hpp"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace unit_tests
//{
//	TEST_CLASS(LinkedListStarterTests)
//	{
//	public:
//		TEST_METHOD(LinkedListDefaultConstructor)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<int> list;
//
//				Assert::IsTrue(list.is_empty());
//				Assert::IsNull(list.get_head());
//
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListCopyConstructor)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<int> a_list;
//				a_list.append(5);
//
//				linked_list<int> b_list(a_list);
//
//				Assert::IsFalse(b_list.is_empty());
//				Assert::AreEqual(5, b_list.first());
//
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListAssignmentOperator)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<size_t> a_list;
//				linked_list<size_t> b_list;
//
//				size_t i;
//
//				size_t values[] = { 5, 15, 25, 35, 45 };
//
//				for (i = 0; i < 5; ++i)
//				{
//					a_list.append(values[i]);
//				}
//
//				b_list = a_list;
//
//				i = 0;
//				for (list_node<size_t> * list_node = b_list.get_head(); list_node != nullptr; list_node = list_node->get_next())
//				{
//					Assert::AreEqual(values[i++], list_node->get_data());
//				}
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListAccessors)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<int> a_list;
//
//				int values[] = { 5, 15, 25, 35, 45 };
//				for (int i = 0; i < 5; ++i)
//				{
//					a_list.append(values[i]);
//				}
//
//				Assert::AreEqual(5, a_list.get_head()->get_data());
//				Assert::AreEqual(45, a_list.get_tail()->get_data());
//
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListAppend)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<size_t> a_list;
//				size_t i;
//
//				size_t values[] = { 5, 15, 25, 35, 45 };
//				for (i = 0; i < 5; ++i)
//				{
//					a_list.append(values[i]);
//				}
//
//				i = 0;
//				for (list_node<size_t> * list_node = a_list.get_head(); list_node != nullptr; list_node = list_node->get_next())
//				{
//					Assert::AreEqual(values[i++], list_node->get_data());
//				}
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListFirstAndLast)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<int> a_list;
//
//				int values[] = { 5, 15, 25, 35, 45 };
//				for (int i = 0; i < 5; ++i)
//				{
//					a_list.append(values[i]);
//				}
//
//				Assert::AreEqual(5, a_list.first());
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListPrepend)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<size_t> a_list;
//				size_t i;
//
//				size_t values[] = { 5, 15, 25, 35, 45 };
//				for (i = 0; i < 5; ++i)
//				{
//					a_list.prepend(values[i]);
//				}
//
//				i = 5;
//				for (list_node<size_t> * list_node = a_list.get_head(); list_node != nullptr; list_node = list_node->get_next())
//				{
//					Assert::AreEqual(values[--i], list_node->get_data());
//				}
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListPurge)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<size_t> a_list;
//
//				size_t values[] = { 5, 15, 25, 35, 45 };
//				for (size_t i = 0; i < 5; ++i)
//				{
//					a_list.append(values[i]);
//				}
//
//				a_list.clear();
//
//				Assert::IsNull(a_list.get_head());
//				Assert::IsNull(a_list.get_tail());
//				Assert::IsTrue(a_list.is_empty());
//
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListBefore)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<int> a_list;
//				int i;
//
//				int values[] = { 5, 15, 25, 35, 45 };
//
//				a_list.append(values[4]);
//				for (i = 3; i >= 0; --i)
//				{
//					a_list.insert_before(values[i], values[i + 1]);
//				}
//
//				i = 0;
//				for (list_node<int> * list_node = a_list.get_head(); list_node != nullptr; list_node = list_node->get_next())
//				{
//					Assert::AreEqual(values[i++], list_node->get_data());
//				}
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListInsertAfter)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<int> a_list;
//				int i;
//
//				int values[] = { 5, 15, 25, 35, 45 };
//
//				a_list.append(values[0]);
//				for (i = 1; i < 5; ++i)
//				{
//					a_list.insert_after(values[i], values[i - 1]);
//				}
//
//				i = 0;
//				for (list_node<int> * list_node = a_list.get_head(); list_node != nullptr; list_node = list_node->get_next())
//				{
//					Assert::AreEqual(values[i++], list_node->get_data());
//				}
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//
//		TEST_METHOD(LinkedListExtract)
//		{
//			crt_check_memory check;
//			try
//			{
//				linked_list<int> list;
//
//				list.append(5);
//				list.extract(5);
//
//				Assert::IsTrue(list.is_empty());
//				Assert::IsNull(list.get_head());
//
//				list.append(5);
//				list.append(10);
//				list.append(15);
//
//				list.extract(10);
//
//				Assert::AreEqual(5, list.first());
//				Assert::AreEqual(15, list.last());
//			}
//			catch (adt_exception adt_exception)
//			{
//				Assert::Fail(adt_exception.adt_what());
//			}
//		}
//	};
//}
//
