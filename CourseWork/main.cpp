#include <iostream>
#include "ActivationFunctions.h"
#include "ActivationFunctions.cpp"
#include <string>

int main()
{
	auto arr1 = rand_uniform(0, 10, 500, 200);
	auto arr2 = rand_uniform(0, 10, 5);
	auto arr3 = rand_uniform(0, 10, 5);

	//std::cout << arr1 << '\n';

	clock_t start = clock();
	for (size_t i = 0; i < 5000; i++)
		arr1.T();
	clock_t end = clock();

	std::cout << end - start;

	return 0;
}