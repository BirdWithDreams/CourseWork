#pragma once
#include <vector>

template <class T>
class Array
{
private:
	T* array;
	std::vector<int> shape;
	int dims;

public:
	Array();
	Array(T* begin, T* end);
	Array(T* arr, int n);
	Array(T** arr, int n, int m);
	Array(int n);
	Array(int n, int m);

	void rand_uniform(T min, T max);
};

//template <class T>
//Array<T> rand_uniform(T min, T max, int n);
//
//template <class T>
//Array<T> rand_uniform(T min, T max, int n, int m);