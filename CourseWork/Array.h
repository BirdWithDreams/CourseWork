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
	using value_type = _Ty;
	using pointer    = _Ty*;
	using ppointer   = _Ty**;

	using self                 = Array<_Ty>;
	using self_pointer         = typename self*;
	using self_reference       = self&;
	using const_self_reference = const self&;

public:
	int shape[2];

private:
	ppointer array;

	self_pointer _T = nullptr;

public:
	Array();
	Array(pointer begin, pointer end);
	Array(pointer arr, int n);
	Array(ppointer arr, int n, int m);
	Array(int n);
	Array(int n, int m);

	Array(std::fstream& fio);

	Array(const_self_reference other);
	self_reference operator=(const_self_reference other);

	Array(self&& other) noexcept;
	self_reference operator=(self&& other) noexcept;

	~Array();

	pointer operator[](int i) const;


	self operator+(const_self_reference _arr) const;

	template<class U>
	self operator+(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator+(U num, const Array<_Ty>& _arr);


	self_reference operator+=(const_self_reference _arr);

	template<class U>
	self_reference operator+=(U num);


	self operator-() const;
	self operator-(const_self_reference _arr) const;

	template<class U>
	self operator-(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator-(U num, const Array<_Ty>& _arr);


	self_reference operator-=(const_self_reference _arr);

	template<class U>
	self_reference operator-=(U num);


	self operator*(const_self_reference _arr) const;

	template<class U>
	self operator*(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator*(U num, const Array<_Ty>& _arr);

	self operator/(const_self_reference _arr) const;

	template<class U>
	self operator/(U num) const;

	template<class _Ty, class U>
	friend Array<_Ty> operator/(U num, const Array<_Ty>& _arr);


	template<class U>
	self operator^(U num) const;


	self dot(const_self_reference _arr) const;

	self_reference T();

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
