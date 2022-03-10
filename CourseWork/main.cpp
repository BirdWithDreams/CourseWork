#include <iostream>
#include "ActivationFunctions.h"
#include "ActivationFunctions.cpp"
#include <string>

int main()
{
	auto arr1 = rand_uniform(-1, 1, 2, 2);
	auto arr2 = rand_uniform(-1, 1, 2, 2);
	std::cout << arr1 << '\n' << arr2 << '\n';

	auto arr = sigmoid(arr1);
	std::cout << arr;

	return 0;
}