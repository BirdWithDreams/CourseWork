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
}
;

//template<class T>
//Array<T>::~Array()
//{
//	int n = this->shape[0];
//	for (int i = 0; i < n; i++)
//		delete[] array[i];
//
//	delete[] array;
//	delete[] shape;
//}
//;

template<class T>
T* Array<T>::operator[](int i)
{
	return array[i];
}

template<class T>
Array<T> Array<T>::operator+(Array<T>& arr2)
{
	if (this->shape[0] == arr2.shape[0] && this->shape[1] == arr2.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];
		T** arr = new T* [n];
		for (int i = 0; i < n; i++)
			arr[i] = new T[m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = this->array[i][j] + arr2[i][j];
		return Array<T>{ arr, n, m };
	}
	return Array<T>();
}

template<class T>
Array<T> Array<T>::operator*(T num)
{
	int n = this->shape[0];
	int m = this->shape[1];
	T** arr = new T * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new T[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = this->array[i][j] * num;

	return Array<T>{ arr, n, m };
}

template<class T>
Array<T> Array<T>::operator*(Array<T>& arr2)
{
	int n1 = this->shape[0],
		m1 = this->shape[1],
		n2 = arr2.shape[0],
		m2 = arr2.shape[1];

	if (n1 == m2)
	{
		T** arr = new T* [n1];
		for (int i = 0; i < n1; i++)
			arr[i] = new T[m2];

		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m2; j++)
			{
				T sum = 0;
				for (int k = 0; k < m1; k++)
					sum += this->array[i][k] * arr2[k][j];
				arr[i][j] = sum;
			}
				
		return Array<T>{arr, n1, m2};
	}

	return Array<T>();
}

template<class T>
Array<T> Array<T>::operator/(T num)
{
	int n = this->shape[0];
	int m = this->shape[1];
	T** arr = new T* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new T[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = this->array[i][j] / num;

	return Array<T>{ arr, n, m };
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
Array<T> operator*(T num, Array<T>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];
	T** arr = new T * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new T[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = _arr[i][j] * num;

	return Array<T>{ arr, n, m };
}

template<class T>
Array<T> operator/(T num, Array<T>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];
	T** arr = new T * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new T[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = num / _arr[i][j];

	return Array<T>{ arr, n, m };
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
