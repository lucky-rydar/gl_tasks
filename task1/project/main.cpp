#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cout << "Invalid input" << endl;
        return -1;
    }

    string input(argv[1]);
    if(input == "help")
    {
        cout << "Usage: ./main help"  << endl \
            << "To be honest I have no idea what should be here" << endl;

    }
}