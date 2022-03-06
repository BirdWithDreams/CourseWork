#include <iostream>
#include "Array.h"
#include "Array.cpp"
#include <vector>


int main()
{
	auto arr1 = rand_uniform(0.0, 10.0, 2, 2);
	auto arr2 = rand_uniform(0.0, 10.0, 2, 2);
	auto arr = 1 - arr1;
	std::cout << arr1 << '\n' << arr;

	return 0;
}