#include "stack.h"
#include "gtest/gtest.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	puts("Google tests...");

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}