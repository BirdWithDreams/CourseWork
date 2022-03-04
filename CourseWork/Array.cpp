#include "Array.h"

template<class T>
Array<T>::Array()
{
	this->array = nullptr;
	shape.push_back(0);
	dims = 0;
};

template<class T>
Array<T>::Array(T* begin, T* end)
{
	int n = end - begin;
	this->array = new T[n];

	for (int i = 0; i < n; i++)
		this->array[i] = begin[i];

	shape.push_back(n);
	dims = 1;
};

template<class T>
Array<T>::Array(T* arr, int n)
{
	this->array = new T[n];

	for (int i = 0; i < n; i++)
		this->array[i] = arr[i];

	shape.push_back(n);
	dims = 1;
};

template<class T>
Array<T>::Array(T** arr, int n, int m)
{
	this->array = new T[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] = arr[i][j];

	shape.push_back(n);
	shape.push_back(m);
	dims = 2;
};

template<class T>
Array<T>::Array(int n)
{
	array = new T[n];

	for (int i = 0; i < n; i++)
		array[i] = 0;

	shape.push_back(n);
	dims = 1;
};

template<class T>
Array<T>::Array(int n, int m)
{
	this->array = new T*[n];
	for (int i = 0; i < n; i++)
		array[i] = new T[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] = 0;

	shape.push_back(n);
	shape.push_back(m);
	dims = 2;
};

template<class T>
void Array<T>::rand_uniform(T min, T max)
{

	switch (dims)
	{
	case 0:
		break;

	case 1:
		for (int i = 0; i < shape[0]; i++)
			array[i] = rand() / static_cast<double>(RAND_MAX) * (max - min) + min;
		break;

	case 2:
		for (int i = 0; i < shape[0]; i++)
			for (int j = 0; j < shape[1]; j++)
				array[i][j] = rand() / static_cast<double>(RAND_MAX) * (max - min) + min;
		break;
	default:
		break;
	}
};

//template<class T>
//Array<T> rand_uniform(T min, T max, int n)
//{
//	Array<T> array{ n };
//	array.rand_uniform(min, max);
//	return array;
//}
//
//template<class T>
//Array<T> rand_uniform(T min, T max, int n, int m)
//{
//	Array<T> array{ n, m };
//	array.rand_uniform(min, max);
//	return array;
//}
