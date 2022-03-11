#include <iostream>
#include "ActivationFunctions.h"
#include "ActivationFunctions.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <string>

int main()
{
	LinkedList<Array<double>> list;
	auto arr1 = rand_uniform(0, 10, 5, 2);
	auto arr2 = rand_uniform(0, 10, 5, 6);
	auto arr3 = rand_uniform(0, 10, 5, 3);

	list.push_back(arr1);
	list.push_back(arr2);
	list.push_back(arr3);
	std::cout << list;
	std::cout << list.front().el;

	return 0;
}