#pragma once
#include <random>
#include <iostream>
#include <cmath>
#include <iomanip>

template <class _Ty>
class Array
{
	template<class _Ty>
	friend std::ostream& operator<<(std::ostream& os, Array<_Ty>& array);

	template<class _Ty>
	friend Array<_Ty> exponent(const Array<_Ty>& _arr);

private:
	_Ty** array;
	int shape[2];
	//int dims;

public:
	Array();
	Array(_Ty* begin, _Ty* end);
	Array(_Ty* arr, int n);
	Array(_Ty** arr, int n, int m);
	Array(int n);
	Array(int n, int m);

	//~Array();

	_Ty* operator[](int i) const;


	Array<_Ty> operator+(Array<_Ty>& _arr) const;

	template<class U>
	Array<_Ty> operator+(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator+(U num, Array<_Ty>& _arr);


	Array<_Ty>& operator+=(Array<_Ty>& _arr);

	template<class U>
	Array<_Ty>& operator+=(U num);


	Array<_Ty> operator-() const;
	Array<_Ty> operator-(Array<_Ty>& _arr) const;

	template<class U>
	Array<_Ty> operator-(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator-(U num, Array<_Ty>& _arr);


	Array<_Ty>& operator-=(Array<_Ty>& _arr);

	template<class U>
	Array<_Ty>& operator-=(U num);


	Array<_Ty> operator*(Array<_Ty>& _arr) const;

	template<class U>
	Array<_Ty> operator*(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator*(U num, Array<_Ty>& _arr);

	Array<_Ty> operator/(Array<_Ty>& _arr) const;

	template<class U>
	Array<_Ty> operator/(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator/(U num, Array<_Ty>& _arr);

	Array<_Ty>& operator=(const Array<_Ty>& other);


	Array<_Ty> dot(const Array<_Ty>& _arr) const;

	void get_shape(int& n, int& m) const;

	void rand_uniform(_Ty min, _Ty max);
};

template <class _Ty = double, class U>
Array<_Ty> rand_uniform(U min, U max, int n);

template <class _Ty = double, class U>
Array<_Ty> rand_uniform(U min, U max, int n, int m);

template<class _Ty>
Array<_Ty> dot(const Array<_Ty>& arr1, const Array<_Ty>& arr2);