#include <vector>
#include <stdexcept>

namespace collections
{
	template <typename T>
	class stack
	{
	public:
		// the task requires *create* method, but I hope that is only for C
		// so I just made constructor

		// creating stack with size
		stack(size_t size) : elems()
		{
			if (size == 0)
				throw std::logic_error("Size of stack can not be zero");
			
			elems.reserve(size);
		}

		// add element on stack
		void push(T elem) 
		{
			if (is_full())
				throw std::out_of_range("Stack is full");

			elems.push_back(elem);
		}
		
		// get top element
		T pop() 
		{
			if (is_empty())
				throw std::out_of_range("Stack is empty");

			T temp = elems[elems.size()-1];
			elems.pop_back();
			
			return temp;
		}
		
		// amount of elements in stack
		size_t capacity()
		{
			return elems.size();
		}
		
		// max amount of elements
		size_t size()
		{
			return elems.capacity();
		}
		
		//just resize
		void resize(size_t new_size)
		{
			if (new_size < elems.size())
				elems.resize(new_size);
			else if (new_size > elems.size())
				elems.reserve(new_size);
		}

	private:
		//this method tells if stack is full or not
		bool is_full()
		{
			return (elems.size() == elems.capacity());
		}

		bool is_empty()
		{
			return elems.empty();
		}

		std::vector<T> elems;
	};
	
}