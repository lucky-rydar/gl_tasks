#include <iostream>
#include <thread>
#include <string>
#include <filesystem>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

void count_files_in_dir(fs::path path, int* counted);
void print_files_in_dir(fs::path path);