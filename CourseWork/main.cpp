#include <iostream>
#include "ActivationFunctions.h"
#include "ActivationFunctions.cpp"
#include <string>

int main()
{
	auto arr1 = rand_uniform(0, 10, 5);
	auto arr2 = rand_uniform(0, 10, 5);
	auto arr3 = rand_uniform(0, 10, 5);

	std::cout << arr1 << '\n'
		<< arr2 << '\n'
		<< arr3 << '\n';

	auto arr = arr1 + arr2 + arr3;

	std::cout << arr;

	return 0;
}