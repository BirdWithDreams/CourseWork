#pragma once
#include <random>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "exceptions.h"

static std::random_device rd;
static std::mt19937 gen(rd());

template <class _Ty>
class Array
{
	template<class _Ty>
	friend std::ostream& operator<<(std::ostream& os, const Array<_Ty>& array);

	template<class _Ty>
	friend Array<_Ty> exponent(const Array<_Ty>& _arr);

public:
	int shape[2];

private:
	_Ty** array;

	Array<_Ty>* _T = nullptr;

public:
	Array();
	Array(_Ty* begin, _Ty* end);
	Array(_Ty* arr, int n);
	Array(_Ty** arr, int n, int m);
	Array(int n);
	Array(int n, int m);

	Array<_Ty>(std::fstream& fio);

	Array(const Array<_Ty>& other);
	Array<_Ty>& operator=(const Array<_Ty>& other);

	Array(Array<_Ty>&& other) noexcept;
	Array<_Ty>& operator=(Array<_Ty>&& other) noexcept;

	~Array();

	_Ty* operator[](int i) const;


	Array<_Ty> operator+(const Array<_Ty>& _arr) const;

	template<class U>
	Array<_Ty> operator+(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator+(U num, const Array<_Ty>& _arr);


	Array<_Ty>& operator+=(const Array<_Ty>& _arr);

	template<class U>
	Array<_Ty>& operator+=(U num);


	Array<_Ty> operator-() const;
	Array<_Ty> operator-(const Array<_Ty>& _arr) const;

	template<class U>
	Array<_Ty> operator-(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator-(U num, const Array<_Ty>& _arr);


	Array<_Ty>& operator-=(const Array<_Ty>& _arr);

	template<class U>
	Array<_Ty>& operator-=(U num);


	Array<_Ty> operator*(const Array<_Ty>& _arr) const;

	template<class U>
	Array<_Ty> operator*(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator*(U num, const Array<_Ty>& _arr);

	Array<_Ty> operator/(const Array<_Ty>& _arr) const;

	template<class U>
	Array<_Ty> operator/(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator/(U num, const Array<_Ty>& _arr);


	template<class U>
	Array<_Ty> operator^(U num) const;


	Array<_Ty> dot(const Array<_Ty>& _arr) const;

	Array<_Ty>& T();

	void save(std::fstream& fio);

	void rand_uniform(_Ty min, _Ty max);
	void randint(_Ty min, _Ty max);

	_Ty sum() const;
	int argmax();
};

template<class _Ty>
Array<_Ty> dot(const Array<_Ty>& arr1, const Array<_Ty>& arr2);

template<class _Ty>
_Ty sum(const Array<_Ty>& _arr);


template<class _Ty>
Array<_Ty> zeros(int n);

template<class _Ty>
Array<_Ty> zeros(int n, int m);

template<class _Ty>
Array<_Ty> ones(int n);

template<class _Ty>
Array<_Ty> ones(int n, int m);


template <class _Ty = double, class U>
Array<_Ty> rand_uniform(U min, U max, int n);

template <class _Ty = double, class U>
Array<_Ty> rand_uniform(U min, U max, int n, int m);

template <class _Ty = int, class U>
Array<_Ty> randint(U min, U max, int n);

template <class _Ty = int, class U>
Array<_Ty> randint(U min, U max, int n, int m);
