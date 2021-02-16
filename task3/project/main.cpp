#include <iostream>
#include <string>
#include "file_counter.h"

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char** argv)
{
	if (argc < 2 || argc > 2)
	{
		cout << "Invalid arguments" << endl;
	}
	
	string input(argv[1]);
	if (input == "--help")
	{
		cout << "Usage: ./main <path>";
	}
	else
	{
		fs::path p(input);
		int counted = 0;
		thread count_files(count_files_in_dir, p, &counted);
		thread print_files(print_paths_in_dir, p);

		count_files.join();
		print_files.join();
		cout << "Amount: " << counted << endl;
	}
}