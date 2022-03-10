#pragma once
#include <random>
#include <iostream>
#include <cmath>

template <class T>
class Array
{
	template<class T>
	friend std::ostream& operator<<(std::ostream& os, Array<T>& array);

	template<class T>
	friend Array<T> exponent(const Array<T>& _arr);

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
	Array<T> operator+(U num) const;

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

	Array<T> operator/(Array<T>& _arr) const;

	template<class U>
	Array<T> operator/(U num) const;

	template<class T, class U>
	friend Array<T> operator/(U num, Array<T>& _arr);


	//Array<T> dot(Array<T> arr2);
	void get_shape(int& n, int& m);

	void rand_uniform(T min, T max);
};

template <class T = double, class U>
Array<T> rand_uniform(U min, U max, int n);

template <class T = double, class U>
Array<T> rand_uniform(U min, U max, int n, int m);
