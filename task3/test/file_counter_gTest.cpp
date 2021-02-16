#include "file_counter.h"
#include "gtest/gtest.h"

TEST(file, print_files_in_dir1)
{
	auto p = fs::current_path();
	ASSERT_NO_THROW(print_files_in_dir(p));
}

TEST(file, print_files_in_dir2)
{
	ASSERT_THROW(print_files_in_dir(fs::path("fhdfjkdt6754564")), std::exception);
}

TEST(file, count_files_in_dir1)
{
	auto p = fs::current_path();
	int c = 0;
	ASSERT_NO_THROW(count_files_in_dir(p, &c));
}

TEST(file, count_files_in_dir2)
{
	int c = 0;
	ASSERT_THROW(count_files_in_dir(fs::path("fhdfjkdt6754564"), &c), std::exception);
}

int main(int argc, char** argv)
{
	puts("Google tests...");

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}