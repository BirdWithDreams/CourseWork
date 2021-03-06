#include "Array.h"

template<class _Ty>
Array<_Ty>::Array() : array(nullptr)
{
	shape[0] = shape[1] = 0;
}
;

template<class _Ty>
Array<_Ty>::Array(pointer begin, pointer end)
{
	int n = end - begin;
	this->array = new pointer [1];
	this->array[0] = new value_type[n];

	for (int i = 0; i < n; i++)
		this->array[0][i] = begin[i];

	shape[0] = 1;
	shape[1] = n;
}
;

template<class _Ty>
Array<_Ty>::Array(pointer arr, int n)
{
	this->array = new pointer [1];
	this->array[0] = new value_type[n];

	for (int i = 0; i < n; i++)
		this->array[0][i] = arr[i];

	shape[0] = 1;
	shape[1] = n;
}
;

template<class _Ty>
Array<_Ty>::Array(ppointer arr, int n, int m)
{
	this->array = new pointer [n];
	for (int i = 0; i < n; i++)
	{
		this->array[i] = new value_type[m];
		for (int j = 0; j < m; j++)
			this->array[i][j] = arr[i][j];
	}

	shape[0] = n;
	shape[1] = m;
}
;

template<class _Ty>
Array<_Ty>::Array(int n)
{
	array = new pointer [1];
	array[0] = new value_type[n];

	shape[0] = 1;
	shape[1] = n;
}
;

template<class _Ty>
Array<_Ty>::Array(int n, int m)
{
	this->array = new pointer [n];
	for (int i = 0; i < n; i++)
		array[i] = new value_type[m];

	shape[0] = n;
	shape[1] = m;
}
;

template<class _Ty>
Array<_Ty>::Array(const_self_reference other) : array{ nullptr }
{
	int 
		n = other.shape[0], 
		m = other.shape[1];

	this->array = new pointer [n];
	for (int i = 0; i < n; i++)
	{
		this->array[i] = new value_type[m];
		for (int j = 0; j < m; j++)
			this->array[i][j] = other[i][j];
	}

	this->shape[0] = n;
	this->shape[1] = m;
}
;

template<class _Ty>
Array<_Ty>::Array(self&& other) noexcept
{
	this->shape[0] = other.shape[0];
	this->shape[1] = other.shape[1];
	this->array = other.array;
	this->_T = other._T;

	other.shape[0] = 0;
	other.shape[1] = 0;
	other.array = nullptr;
	other._T = nullptr;
}
;

template<class _Ty>
Array<_Ty>& Array<_Ty>::operator=(self&& other) noexcept
{
	if (this == &other) return *this;
	if (this->array)
	{
		for (int i = 0; i < this->shape[0]; i++)
			delete[] this->array[i];
		delete[] this->array;
	}
	this->shape[0] = other.shape[0];
	this->shape[1] = other.shape[1];
	this->array = other.array;
	this->_T = other._T;

	other.shape[0] = 0;
	other.shape[1] = 0;
	other.array = nullptr;
	other._T = nullptr;

	return *this;
}
;

template<class _Ty>
Array<_Ty>::~Array()
{
	int n = this->shape[0];
	for (int i = 0; i < n; i++)
		delete[] array[i];

	delete[] this->array;
}
;

template<class _Ty>
_Ty* Array<_Ty>::operator[](int i) const
{
	if (i >= this->shape[0])
		throw IndexError();

	return array[i];
}
;

template<class _Ty>
Array<_Ty> Array<_Ty>::operator+(const_self_reference _arr) const
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];

		self res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = this->array[i][j] + _arr[i][j];

		return res;
	}
	else
		throw ShapeError(this->shape[0], this->shape[1], _arr.shape[0], _arr.shape[1]);
}
;

template<class _Ty>
Array<_Ty>::Array(std::fstream& fio)
{
	fio.read(reinterpret_cast<char*>(this->shape), sizeof(int) * 2);

	this->array = new pointer [this->shape[0]];
	for (int i = 0; i < this->shape[0]; i++)
		this->array[i] = new value_type[this->shape[1]];

	for (int i = 0; i < this->shape[0]; i++)
		fio.read(reinterpret_cast<char*>((*this)[i]), sizeof(value_type) * this->shape[1]);
}

template<class _Ty>
template<class U>
Array<_Ty> Array<_Ty>::operator+(U num) const
{
	int n = this->shape[0];
	int m = this->shape[1];

	self res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = this->array[i][j] + static_cast<value_type>(num);

	return res;
}
;

template<class _Ty, class U>
Array<_Ty> operator+(U num, Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];

	Array<_Ty> res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = _arr[i][j] + static_cast<_Ty>(num);

	return res;
}
;

template<class _Ty>
template<class U>
Array<_Ty>& Array<_Ty>::operator-=(U num)
{
	int n = this->shape[0];
	int m = this->shape[1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] -= static_cast<value_type>(num);
	return *this;
}
;

template<class _Ty>
template<class U>
Array<_Ty> Array<_Ty>::operator*(U num) const
{
	int n = this->shape[0];
	int m = this->shape[1];

	self res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = this->array[i][j] * static_cast<value_type>(num);

	return res;
}
;

template<class _Ty>
Array<_Ty> Array<_Ty>::operator*(const_self_reference _arr) const
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];

		self res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = this->array[i][j] * _arr[i][j];

		return res;
	}
	else
		throw ShapeError(this->shape[0], this->shape[1], _arr.shape[0], _arr.shape[1]);
}
;

template<class _Ty>
Array<_Ty> Array<_Ty>::operator/(const_self_reference _arr) const
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];

		self res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = this->array[i][j] / _arr[i][j];

		return res;
	}
	else
		throw ShapeError(this->shape[0], this->shape[1], _arr.shape[0], _arr.shape[1]);
}
;

template<class _Ty>
template<class U>
Array<_Ty> Array<_Ty>::operator/(U num) const
{
	int n = this->shape[0];
	int m = this->shape[1];

	self res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = this->array[i][j] / static_cast<value_type>(num);

	return res;
}
;

template<class _Ty>
template<class U>
Array<_Ty> Array<_Ty>::operator^(U num) const
{
	int n = this->shape[0];
	int m = this->shape[1];

	self res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = pow(this->array[i][j], static_cast<value_type>(num));

	return res;
}
;

template<class _Ty>
Array<_Ty>& Array<_Ty>::operator+=(const_self_reference _arr)
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				this->array[i][j] += _arr[i][j];
		return *this;
	}
	else
		throw ShapeError(this->shape[0], this->shape[1], _arr.shape[0], _arr.shape[1]);
}
;

template<class _Ty>
Array<_Ty> Array<_Ty>::operator-() const
{
	int n = this->shape[0];
	int m = this->shape[1];

	self res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = -this->array[i][j];

	return res;
}
;

template<class _Ty>
template<class U>
Array<_Ty>& Array<_Ty>::operator+=(U num)
{
	int n = this->shape[0];
	int m = this->shape[1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] += static_cast<value_type>(num);
	return *this;
}
;

template<class _Ty>
template<class U>
Array<_Ty> Array<_Ty>::operator-(U num) const
{
	int n = this->shape[0];
	int m = this->shape[1];

	self res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = this->array[i][j] - static_cast<value_type>(num);

	return res;
}
;

template<class _Ty>
Array<_Ty> Array<_Ty>::operator-(const_self_reference _arr) const
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];

		self res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = this->array[i][j] - _arr[i][j];

		return res;
	}
	else
		throw ShapeError(this->shape[0], this->shape[1], _arr.shape[0], _arr.shape[1]);
}
;

template<class _Ty>
Array<_Ty>& Array<_Ty>::operator-=(const_self_reference _arr)
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				this->array[i][j] -= _arr[i][j];
		return *this;
	}
	else
		throw ShapeError(this->shape[0], this->shape[1], _arr.shape[0], _arr.shape[1]);
}
;

template<class _Ty>
Array<_Ty>& Array<_Ty>::operator=(const_self_reference other)
{
	if (this == &other) return *this;

	int 
		n = other.shape[0],
		m = other.shape[1];

	if (this->shape[0] == n && this->shape[1] == m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				this->array[i][j] = other[i][j];
		return *this;
	}

	if (this->array)
	{
		for (int i = 0; i < this->shape[0]; i++)
			delete[] this->array[i];
		delete[] this->array;
	}

	this->array = new pointer [n];
	for (int i = 0; i < n; i++)
	{
		this->array[i] = new value_type[m];
		for (int j = 0; j < m; j++)
			this->array[i][j] = other[i][j];
	}

	this->shape[0] = n;
	this->shape[1] = m;
	return *this;
}
;

template<class _Ty>
Array<_Ty> Array<_Ty>::dot(const_self_reference _arr) const
{
	int n1 = this->shape[0],
		m1 = this->shape[1],
		n2 = _arr.shape[0],
		m2 = _arr.shape[1];

	if (m1 == n2)
	{
		self res(n1, m2);
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m2; j++)
			{
				_Ty sum = 0;
				for (int k = 0; k < m1; k++)
					sum += this->array[i][k] * _arr[k][j];
				res[i][j] = sum;
			}

		return res;
	}
	else
		throw MatMulError(m1, n2);
}
;

template<class _Ty>
Array<_Ty>& Array<_Ty>::T()
{
	int n = this->shape[0];
	int m = this->shape[1];

	if (!this->_T)
	{
		this->_T = new self(m, n);

		this->_T->_T = this;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(*_T)[j][i] = this->array[i][j];

	return *_T;
}
template<class _Ty>
void Array<_Ty>::save(std::fstream& fio)
{
	fio.write(reinterpret_cast<char*>(this->shape), sizeof(int) * 2);
	for (int i = 0; i < this->shape[0]; i++)
		fio.write(reinterpret_cast<char*>((*this)[i]), sizeof(_Ty) * this->shape[1]);
}
;

template<class _Ty>
void Array<_Ty>::rand_uniform(_Ty min, _Ty max)
{
	std::uniform_real_distribution<> dist(min, max);
	for (int i = 0; i < shape[0]; i++)
		for (int j = 0; j < shape[1]; j++)
			array[i][j] = dist(gen);
}
;

template<class _Ty>
void Array<_Ty>::randint(_Ty min, _Ty max)
{
	std::uniform_int_distribution<> dist(min, max);
	for (int i = 0; i < shape[0]; i++)
		for (int j = 0; j < shape[1]; j++)
			array[i][j] = dist(gen);
}
;

template<class _Ty>
_Ty Array<_Ty>::sum() const
{
	value_type s = 0;
	int n = this->shape[0];
	int m = this->shape[1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			s += this->array[i][j];

	return s;
}

template<class _Ty>
int Array<_Ty>::argmax()
{
	value_type max = this->array[0][0];
	int index = 0;

	int n = this->shape[0];
	int m = this->shape[1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (this->array[i][j] > max)
			{
				max = this->array[i][j];
				index = i * n + j;
			}

	return index;
}
;

template<class _Ty>
std::ostream& operator<<(std::ostream& os, const Array<_Ty>& array)
{
	for (int i = 0; i < array.shape[0]; i++)
	{
		for (int j = 0; j < array.shape[1]; j++)
			os << std::setiosflags(std::ios::left)
			<< std::setw(12) << array[i][j];
		os << '\n';
	}
	os << std::flush;
	return os;
}
;

template<class _Ty, class U>
Array<_Ty> operator-(U num, Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];

	Array<_Ty> res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = static_cast<_Ty>(num) - _arr[i][j];

	return res;
}
;

template<class _Ty, class U>
Array<_Ty> operator*(U num, const Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];

	Array<_Ty> res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = _arr[i][j] * static_cast<_Ty>(num);

	return res;
}
;

template<class _Ty, class U>
Array<_Ty> operator/(U num, Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];

	Array<_Ty> res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = static_cast<_Ty>(num) / _arr[i][j];

	return res;
}
;

template<class _Ty = double, class U>
Array<_Ty> rand_uniform(U min, U max, int n)
{
	Array<_Ty> array{ n };
	array.rand_uniform(static_cast<_Ty>(min), static_cast<_Ty>(max));
	return array;
}
;

template<class _Ty = double, class U>
Array<_Ty> rand_uniform(U min, U max, int n, int m)
{
	Array<_Ty> array{ n, m };
	array.rand_uniform(static_cast<_Ty>(min), static_cast<_Ty>(max));
	return array;
}
;

template<class _Ty, class U>
Array<_Ty> randint(U min, U max, int n)
{
	Array<_Ty> array{ n };
	array.randint(static_cast<_Ty>(min), static_cast<_Ty>(max));
	return array;
}
;

template<class _Ty, class U>
Array<_Ty> randint(U min, U max, int n, int m)
{
	Array<_Ty> array{ n, m };
	array.randint(static_cast<_Ty>(min), static_cast<_Ty>(max));
	return array;
}
;

template<class _Ty>
Array<_Ty> dot(const Array<_Ty>& arr1, const Array<_Ty>& arr2)
{
	return arr1.dot(arr2);
}
;

template<class _Ty>
_Ty sum(const Array<_Ty>& _arr)
{
	return _arr.sum();
}
;

template<class _Ty>
Array<_Ty> zeros(int n)
{
	Array<_Ty> res{ n };
	for (int i = 0; i < n; i++)
		res[0][i] = 0;

	return res;
}
;

template<class _Ty>
Array<_Ty> zeros(int n, int m)
{
	Array<_Ty> res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = 0;

	return res;
}
;

template<class _Ty>
Array<_Ty> ones(int n)
{
	Array<_Ty> res{ n };
	for (int i = 0; i < n; i++)
		res[0][i] = 1;

	return res;
}
;

template<class _Ty>
Array<_Ty> ones(int n, int m)
{
	Array<_Ty> res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = 1;

	return res;
}
;

template<class _Ty>
Array<_Ty> exponent(const Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];

	Array<_Ty> res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = exp(_arr.array[i][j]);

	return res;
}
;
