#include <iostream>
#include <string>
#include "fibonacci.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		cout << "Enter at least one argument" << endl;
		return -1;
	}
	if (argc > 2)
	{
		cout << "Too many arguments" << endl;
		return -1;
	}

	string arg(argv[1]);
	if (arg == "help")
	{
		cout << endl << "using: ./main <positive-integer>" << endl;
	}
	else
	{
		try
		{
			cout << fibonacci_sum(stoull(arg)) << endl;
		}
		catch (std::exception& e)
		{
			cout << "Can't convert to integer" << endl;
		}
	}

	return 0;
}