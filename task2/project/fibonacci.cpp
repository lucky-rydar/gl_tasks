#include "fibonacci.h"

uint64_t fibonacci(uint64_t pre_last, uint64_t last, uint64_t n)
{
	if (n == 1)
		return 0;
	else
	{
		return last + fibonacci(last, pre_last + last, n - 1);
	}
}

uint64_t fibonacci_sum(uint64_t n)
{
	if (n == 0)
		return 0;
	else
		return fibonacci(0, 1, n);
}