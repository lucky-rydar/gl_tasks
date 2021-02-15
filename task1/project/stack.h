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
		stack(size_t size) : max_amount(size)
		{
			if (size == 0)
				throw std::logic_error("Size of stack can not be zero");

		}

		// add element on stack
		void push(T elem) 
		{
			if (is_full())
				throw std::out_of_range("Stack overflow");

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
			return max_amount;
		}
		
		//just resize
		void resize(size_t new_size)
		{
			if (new_size < max_amount)
			{
				max_amount = new_size;
				this->elems.resize(max_amount);
			}
			else if (new_size > max_amount)
			{
				max_amount = new_size;
			}
		}

	private:
		//this method tells if stack is full or not
		bool is_full()
		{
			return (elems.size() == max_amount);
		}

		bool is_empty()
		{
			return (elems.size() == 0);
		}

		std::vector<T> elems;
		size_t max_amount;
	};
	
}