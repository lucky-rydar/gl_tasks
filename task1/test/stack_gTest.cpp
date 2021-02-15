#include "stack.h"
#include "gtest/gtest.h"
#include <stdio.h>

using namespace collections;

TEST(stack, stack)
{
	ASSERT_THROW(stack<int> s(0), std::logic_error);
	
	stack<int> a(2);
	ASSERT_EQ(a.capacity(), 0);
	ASSERT_EQ(a.size(), 2);
}

TEST(stack, push)
{
	stack<int> s(2);
	s.push(1);
	
	ASSERT_EQ(s.capacity(), 1);

	s.push(1);
	ASSERT_THROW(s.push(1), std::out_of_range);
}

TEST(stack, pop)
{
	stack<int> s(1);
	
	s.push(1337);
	ASSERT_EQ(1337, s.pop());

	ASSERT_THROW(s.pop(), std::out_of_range);

}

TEST(stack, resize1)
{
	stack<int> s(4);
	for (int i = 0; i < 4; i++)
		s.push(i);

	s.resize(3);
	ASSERT_EQ(s.pop(), 2);

	
	s.resize(8);
	s.push(228);
	ASSERT_EQ(s.pop(), 228);
}

TEST(stack, resize2)
{
	stack<int> s(1);
	s.push(1);
	s.resize(2);
	ASSERT_NO_THROW(s.push(1337));
	ASSERT_EQ(s.pop(), 1337);
}

int main(int argc, char** argv)
{
	puts("Google tests...");

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}