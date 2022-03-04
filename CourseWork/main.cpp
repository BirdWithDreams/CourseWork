#include <iostream>
#include "Array.h"
#include "Array.cpp"


int main()
{
	auto arr = rand_uniform<double>(-1, 1, 5);
	std::cout << arr[0][1];
	return 0;
}