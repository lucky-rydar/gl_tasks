#include "fibonacci.h"
#include "gtest/gtest.h"

TEST(fibonacci, sum)
{
	ASSERT_EQ(fibonacci_sum(5), 7);
	ASSERT_EQ(fibonacci_sum(4), 4);
	ASSERT_EQ(fibonacci_sum(3), 2);
}

TEST(fibonacci, zero_arg)
{
	ASSERT_EQ(fibonacci_sum(0), 0);
}

int main(int argc, char** argv)
{
	puts("Google tests...");

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}