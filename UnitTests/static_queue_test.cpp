#include "stdafx.h"
#include "CppUnitTest.h"

#include "crt_check_memory.hpp"
#include "adt_exception.hpp"
#include "static_queue.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(static_queue_test)
	{
	public:

		TEST_METHOD(static_queue_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			static_queue<int> q(5);

			// Act

			// Assert
			Assert::IsTrue(q.empty());
			Assert::IsFalse(q.full());
		}

		TEST_METHOD(static_queue_copy_constructor_test)
		{
			// Arrange
			crt_check_memory check;
			static_queue<int> q(5);

			// Act
			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);
			q.enqueue(4);
			q.enqueue(5);

			auto q2 = q;

			// Assert
			Assert::IsFalse(q2.empty());
			Assert::IsTrue(q2.full());
			Assert::AreEqual(q.get_queue_element(2), q2.get_queue_element(2));
		}

		TEST_METHOD(static_queue_enqueue_test)
		{
			// Arrange
			crt_check_memory check;
			static_queue<int> q(5);

			// Act
			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);
			q.enqueue(4);
			q.enqueue(5);

			// Assert
			Assert::IsFalse(q.empty());
			Assert::IsTrue(q.full());
			Assert::AreEqual(1, q.front());
			Assert::AreEqual(5, q.get_queue_element(4));
		}

		TEST_METHOD(static_queue_dequeue_test)
		{
			// Arrange
			crt_check_memory check;
			static_queue<int> q(5);
			static_queue<int> q2(5);

			// Act
			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);
			q.enqueue(4);
			q.enqueue(5);

			q2.enqueue(1);
			q2.enqueue(2);
			q2.enqueue(3);
			q2.enqueue(4);
			q2.enqueue(5);

			const auto data = q.dequeue();
			const int size = q.size();

			// Assert
			Assert::IsFalse(q.full());
			Assert::AreEqual(1, data);
			Assert::AreEqual(2, q.front());
			Assert::AreEqual(4, size);
		}

		TEST_METHOD(static_queue_dequeue_test2)
		{
			// Arrange
			crt_check_memory check;
			static_queue<int> q(5);

			// Act
			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);
			q.enqueue(4);
			q.enqueue(5);

			const auto one = q.dequeue();
			const auto two = q.dequeue();
			const auto three = q.dequeue();
			const auto four = q.dequeue();
			const auto five = q.dequeue();

			const int size = q.size();

			// Assert
			Assert::IsFalse(q.full());
			Assert::IsTrue(q.empty());
			Assert::AreEqual(0, size);
			Assert::AreEqual(1, one);
			Assert::AreEqual(2, two);
			Assert::AreEqual(3, three);
			Assert::AreEqual(4, four);
			Assert::AreEqual(5, five);
		}

		TEST_METHOD(static_queue_clear_test)
		{
			// Arrange
			crt_check_memory check;
			static_queue<int> q(5);

			// Act
			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);
			q.enqueue(4);
			q.enqueue(5);

			q.clear();
			const int size = q.size();

			// Assert
			Assert::IsTrue(q.empty());
			Assert::AreEqual(0, size);
		}

		TEST_METHOD(static_queue_front_test2)
		{
			// Arrange
			crt_check_memory check;
			static_queue<int> q(5);

			// Act
			q.enqueue(1);
			q.enqueue(2);
			q.enqueue(3);
			q.enqueue(4);
			q.enqueue(5);

			const auto one = q.front();
			q.dequeue();
			const auto two = q.front();
			q.dequeue();
			const auto three = q.front();
			q.dequeue();
			const auto four = q.front();
			q.dequeue();
			const auto five = q.front();
			q.dequeue();

			// Assert
			Assert::AreEqual(1, one);
			Assert::AreEqual(2, two);
			Assert::AreEqual(3, three);
			Assert::AreEqual(4, four);
			Assert::AreEqual(5, five);
		}
	};
}