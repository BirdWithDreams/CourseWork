#include "Array.h"

template<class T>
Array<T>::Array()
{
	this->array = nullptr;
	shape[0] = shape[1] = 0;
	//dims = 0;
};

template<class T>
Array<T>::Array(T* begin, T* end)
{
	int n = end - begin;
	this->array = new T*[1];
	this->array[0] = new T[n];

	for (int i = 0; i < n; i++)
		this->array[0][i] = begin[i];

	shape[0] = 1;
	shape[1] = n;
};

template<class T>
Array<T>::Array(T* arr, int n)
{
	this->array = new T*[1];
	this->array[0] = new T[n];

	for (int i = 0; i < n; i++)
		this->array[0][i] = arr[i];

	shape[0] = 1;
	shape[1] = n;
};

template<class T>
Array<T>::Array(T** arr, int n, int m)
{
	this->array = new T*[n];
	for (int i = 0; i < n; i++)
		this->array[i] = new T[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] = arr[i][j];

	shape[0] = n;
	shape[1] = m;
};

template<class T>
Array<T>::Array(int n)
{
	array = new T*[1];
	array[0] = new T[n];

	for (int i = 0; i < n; i++)
		array[0][i] = 0;

	shape[0] = 1;
	shape[1] = n;
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

	shape[0] = n;
	shape[1] = m;
};

template<class T>
T* Array<T>::operator[](int i)
{
	return array[i];
}

template<class T>
void Array<T>::rand_uniform(T min, T max)
{
	for (int i = 0; i < shape[0]; i++)
		for (int j = 0; j < shape[1]; j++)
			array[i][j] = rand() / static_cast<double>(RAND_MAX) * (max - min) + min;
};

template<class T>
std::ostream& operator<<(std::ostream& os, Array<T>& array)
{
	for (int i = 0; i < array.shape[0]; i++)
	{
		for (int j = 0; j < array.shape[1]; j++)
			os << array[i][j] << '\t';
		os << '\n';
	}
	return os;
}

template<class T>
Array<T> rand_uniform(T min, T max, int n)
{
	Array<T> array{ n };
	array.rand_uniform(min, max);
	return array;
}

template<class T>
Array<T> rand_uniform(T min, T max, int n, int m)
{
	Array<T> array{ n, m };
	array.rand_uniform(min, max);
	return array;
}
