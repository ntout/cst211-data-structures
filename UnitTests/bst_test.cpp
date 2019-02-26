#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "adt_exception.hpp"
#include "bst_tree.hpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(bst_tree_test)
	{
	public:

		TEST_METHOD(bst_string_key_test)
		{
			//crt_check_memory check;
			bst_tree<std::string, int> my_tree;
			const int correct_order[] = { 11, 12, 18, 20, 22, 25 };

			std::vector<int> tree_traversal;
			const auto visit = [&](const pair_node<std::string, int> * const node)
			{ tree_traversal.push_back(node->get_data()); };

			my_tree.set_visit_function(visit);

			my_tree.insert("1234", 20);
			my_tree.insert("12", 12);
			my_tree.insert("123456", 25);
			my_tree.insert("1", 11);
			my_tree.insert("123", 18);
			my_tree.insert("12345", 22);

			my_tree.in_order();

			for (size_t i = 0; i < tree_traversal.size(); ++i)
			{
				Assert::AreEqual(correct_order[i], tree_traversal[i]);
			}
		}

		TEST_METHOD(bst_in_order_test)
		{
			crt_check_memory check;
			bst_tree<int, std::string> my_tree;
			const int correct_order[] = { 11, 12, 18, 20, 22, 25 };

			std::vector<int> tree_traversal;
			const auto visit = [&](const pair_node<int, std::string> * const node)
			{ tree_traversal.push_back(node->get_key()); };

			my_tree.set_visit_function(visit);

			my_tree.insert(20, "Twenty"		);
			my_tree.insert(12, "Twelve"		);
			my_tree.insert(25, "Twenty-five");
			my_tree.insert(11, "Eleven"		);
			my_tree.insert(18, "Eighteen"	);
			my_tree.insert(22, "Twenty-two"	);

			my_tree.in_order();
			
			for (size_t i = 0; i < tree_traversal.size(); ++i)
			{
				Assert::AreEqual(correct_order[i], tree_traversal[i]);
			}
		}

		TEST_METHOD(bst_pre_order_test)
		{
			//crt_check_memory check;
			bst_tree<int, std::string> my_tree;
			const int correct_order[] = { 20, 12, 11, 18, 25, 22 };

			std::vector<int> tree_traversal;
			const auto visit = [&](const pair_node<int, std::string> * const node)
			{ tree_traversal.push_back(node->get_key()); };

			my_tree.set_visit_function(visit);

			my_tree.insert(20, "Twenty");
			my_tree.insert(12, "Twelve");
			my_tree.insert(25, "Twenty-five");
			my_tree.insert(11, "Eleven");
			my_tree.insert(18, "Eighteen");
			my_tree.insert(22, "Twenty-two");

			my_tree.pre_order();

			for (size_t i = 0; i < tree_traversal.size(); ++i)
			{
				Assert::AreEqual(correct_order[i], tree_traversal[i]);
			}
		}

		TEST_METHOD(bst_post_order_test)
		{
			//crt_check_memory check;
			bst_tree<int, std::string> my_tree;
			const int correct_order[] = { 11, 18, 12, 22, 25, 20 };

			std::vector<int> tree_traversal;
			const auto visit = [&](const pair_node<int, std::string> * const node)
			{ tree_traversal.push_back(node->get_key()); };

			my_tree.set_visit_function(visit);

			my_tree.insert(20, "Twenty");
			my_tree.insert(12, "Twelve");
			my_tree.insert(25, "Twenty-five");
			my_tree.insert(11, "Eleven");
			my_tree.insert(18, "Eighteen");
			my_tree.insert(22, "Twenty-two");

			my_tree.post_order();

			for (size_t i = 0; i < tree_traversal.size(); ++i)
			{
				Assert::AreEqual(correct_order[i], tree_traversal[i]);
			}
		}

		TEST_METHOD(bst_breadth_first_test)
		{
			//crt_check_memory check;
			bst_tree<int, std::string> my_tree;
			const int correct_order[] = { 20, 12, 25, 11, 18, 22 };

			std::vector<int> tree_traversal;
			const auto visit = [&](const pair_node<int, std::string> * const node)
			{ tree_traversal.push_back(node->get_key()); };

			my_tree.set_visit_function(visit);

			my_tree.insert(20, "Twenty");
			my_tree.insert(12, "Twelve");
			my_tree.insert(25, "Twenty-five");
			my_tree.insert(11, "Eleven");
			my_tree.insert(18, "Eighteen");
			my_tree.insert(22, "Twenty-two");

			my_tree.breadth_first();

			for (size_t i = 0; i < tree_traversal.size(); ++i)
			{
				Assert::AreEqual(correct_order[i], tree_traversal[i]);
			}
		}

		TEST_METHOD(bst_remove_test)
		{
			//crt_check_memory check;
			bst_tree<int, std::string> my_tree;
			const int correct_order[] = { 12, 18, 22 };

			std::vector<int> tree_traversal;
			const auto visit = [&](const pair_node<int, std::string> * const node)
			{ tree_traversal.push_back(node->get_key()); };

			my_tree.set_visit_function(visit);

			my_tree.insert(20, "Twenty");
			my_tree.insert(12, "Twelve");
			my_tree.insert(25, "Twenty-five");
			my_tree.insert(11, "Eleven");
			my_tree.insert(18, "Eighteen");
			my_tree.insert(22, "Twenty-two");

			my_tree.remove(20);
			my_tree.remove(11);
			my_tree.remove(25);
			//my_tree.remove(34);

			my_tree.in_order();

			for (size_t i = 0; i < tree_traversal.size(); ++i)
			{
				Assert::AreEqual(correct_order[i], tree_traversal[i]);
			}
		}

		TEST_METHOD(bst_search_test)
		{
			//crt_check_memory check;
			bst_tree<int, std::string> my_tree;
			const int correct_order_key[] = { 11, 12, 18, 20, 22, 25 };
			const std::string correct_order_value[] = 
				{ "Eleven", "Twelve", "Eighteen", "Twenty", "Twenty-two", "Twenty-five" };

			std::vector<std::string> tree_traversal;
			const auto visit = [&](const pair_node<int, std::string> * const node)
			{ tree_traversal.push_back(node->get_data()); };

			my_tree.set_visit_function(visit);

			my_tree.insert(20, "Twenty");
			my_tree.insert(12, "Twelve");
			my_tree.insert(25, "Twenty-five");
			my_tree.insert(11, "Eleven");
			my_tree.insert(18, "Eighteen");
			my_tree.insert(22, "Twenty-two");

			my_tree.in_order();

			for (size_t i = 0; i < tree_traversal.size(); ++i)
			{
				Assert::AreEqual(correct_order_value[i], my_tree.search(correct_order_key[i]));
			}
		}

		TEST_METHOD(bst_empty_test)
		{
			//crt_check_memory check;
			bst_tree<int, std::string> my_tree;

			std::vector<int> tree_traversal;
			const auto visit = [&](const pair_node<int, std::string> * const node)
			{ tree_traversal.push_back(node->get_key()); };

			my_tree.set_visit_function(visit);

			Assert::IsTrue(my_tree.empty());

			my_tree.insert(20, "Twenty");
			my_tree.insert(12, "Twelve");
			my_tree.insert(25, "Twenty-five");
			my_tree.insert(11, "Eleven");
			my_tree.insert(18, "Eighteen");
			my_tree.insert(22, "Twenty-two");

			Assert::IsFalse(my_tree.empty());
		}

		TEST_METHOD(bst_clear_test)
		{
			//crt_check_memory check;
			bst_tree<int, std::string> my_tree;

			std::vector<int> tree_traversal;
			const auto visit = [&](const pair_node<int, std::string> * const node)
			{ tree_traversal.push_back(node->get_key()); };

			my_tree.set_visit_function(visit);

			my_tree.insert(20, "Twenty");
			my_tree.insert(12, "Twelve");
			my_tree.insert(25, "Twenty-five");
			my_tree.insert(11, "Eleven");
			my_tree.insert(18, "Eighteen");
			my_tree.insert(22, "Twenty-two");

			Assert::IsFalse(my_tree.empty());
			my_tree.clear();
			Assert::IsTrue(my_tree.empty());
		}
	};
}