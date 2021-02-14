#include <vector>

namespace collections
{
	template <typename T>
	class stack
	{
	public:
		stack();
		stack(size_t size); // creating stack with size
		void push(T elem); // add element on stack
		T pop(); // get top element
		size_t capacity(); // amount of elements in stack
		size_t size(); // maxi amount of elements

	private:
		std::vector<T> data;
	};
}