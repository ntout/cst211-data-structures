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

		TEST_METHOD(bst_in_order_test)
		{
			crt_check_memory check;
			bst_tree<int, std::string> my_tree;
			const int correct_order[] = { 11, 12, 18, 20, 22, 25 };

			std::vector<int> tree_traversal;
			const auto visit = [&](const pair_node<int, std::string> * const node)
			{ tree_traversal.push_back(node->get_key()); };

			my_tree.set_visit_function(visit);

			my_tree.insert(20, "Twenty");
			//my_tree.insert(12, "Twelve");
			//my_tree.insert(25, "Twenty-five");
			//my_tree.insert(11, "Eleven");
			//my_tree.insert(18, "Eighteen");
			//my_tree.insert(22, "Twenty-two");

			//my_tree.in_order();

			//for (size_t i = 0; i < tree_traversal.size(); ++i)
			//{
			//	Assert::AreEqual(correct_order[i], tree_traversal[i]);
			//}
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
	};
}