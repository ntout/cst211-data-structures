#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "adt_exception.hpp"
#include "static_stack.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(static_stack_test)
	{
	public:

		TEST_METHOD(stack_push_pop_test)
		{
			// Arrange
			crt_check_memory check;
			static_stack<int> stack(5);

			// Act
			for(auto i{0}; i < 5; ++i)
			{
				stack.push(i);
			}

			// Assert
			for (auto i{ 5 }; i > 0; --i)
			{
				Assert::AreEqual(i - 1, stack.pop());
				int t = stack.get_top();
				Assert::AreEqual(i - 2, t);
			}
		}

		TEST_METHOD(stack_empty_test)
		{
			// Arrange
			crt_check_memory check;
			static_stack<int> stack(5);

			// Act
			for (auto i{ 0 }; i < 5; ++i)
			{
				stack.push(i);
			}

			// Assert
			Assert::IsFalse(stack.empty());
			stack.clear();
			Assert::IsTrue(stack.empty());
		}
	};
}