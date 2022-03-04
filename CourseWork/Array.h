#pragma once
#include <vector>

template <class T>
class Array
{
private:
	T** array;
	int shape[2];
	//int dims;

public:
	Array();
	Array(T* begin, T* end);
	Array(T* arr, int n);
	Array(T** arr, int n, int m);
	Array(int n);
	Array(int n, int m);

	T* operator[](int i);

	void rand_uniform(T min, T max);
};

//template <class T>
//Array<T> rand_uniform(T min, T max, int n);
//
//template <class T>
//Array<T> rand_uniform(T min, T max, int n, int m);