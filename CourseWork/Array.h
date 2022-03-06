#pragma once
#include <iostream>

template <class T>
class Array
{
	template<class T>
	friend std::ostream& operator<<(std::ostream& os, Array<T>& array);
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

	//~Array();

	T* operator[](int i);
	Array<T> operator+(Array<T>& arr2);

	Array<T> operator*(T num);
	template<class T>
	friend Array<T> operator*(T num, Array<T>& arr);

	Array<T> operator*(Array<T>& arr2);
	Array<T> operator/(T num);
	template<class T>
	friend Array<T> operator/(T num, Array<T>& _arr);
	//bool operator bool();
	
	//Array<T> dot(Array<T> arr2);

	void rand_uniform(T min, T max);
};

template <class T>
Array<T> rand_uniform(T min, T max, int n);

template <class T>
Array<T> rand_uniform(T min, T max, int n, int m);