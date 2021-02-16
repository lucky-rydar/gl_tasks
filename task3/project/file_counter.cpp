#include "file_counter.h"

void count_files_in_dir(fs::path path, int* counted)
{
	using fp = bool(*)(const std::filesystem::path&);
	*counted = std::count_if(fs::directory_iterator(path), fs::directory_iterator{}, (fp)fs::is_regular_file);
}

void print_files_in_dir(fs::path path)
{
	fs::directory_iterator i(path);
	for (; i != fs::directory_iterator{}; i++)
	{
		if (i->is_regular_file())
			cout << i->path().filename() << endl;
	}
}