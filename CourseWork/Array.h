#pragma once
#include <iostream>
#include <cmath>

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


	Array<T> operator+(Array<T>& _arr) const;

	template<class U>
	Array<T> operator+(U num);

	template<class T, class U>
	friend Array<T> operator+(U num, Array<T>& _arr);


	Array<T>& operator+=(Array<T>& _arr);

	template<class U>
	Array<T>& operator+=(U num);


	Array<T> operator-() const;
	Array<T> operator-(Array<T>& _arr) const;

	template<class U>
	Array<T> operator-(U num) const;

	template<class T, class U>
	friend Array<T> operator-(U num, Array<T>& _arr);


	Array<T>& operator-=(Array<T>& _arr);

	template<class U>
	Array<T>& operator-=(U num);


	Array<T> operator*(Array<T>& _arr) const;

	template<class U>
	Array<T> operator*(U num) const;

	template<class T, class U>
	friend Array<T> operator*(U num, Array<T>& _arr);


	template<class U>
	Array<T> operator/(U num) const;

	template<class T, class U>
	friend Array<T> operator/(U num, Array<T>& _arr);


	//Array<T> dot(Array<T> arr2);

	void rand_uniform(T min, T max);
};

template <class T>
Array<T> rand_uniform(T min, T max, int n);

template <class T>
Array<T> rand_uniform(T min, T max, int n, int m);

template<class T>
Array<T> exponent(Array<T>& _arr);