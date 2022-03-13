#include "Array.h"

template<class _Ty>
Array<_Ty>::Array()
{
	this->array = nullptr;
	shape[0] = shape[1] = 0;
	//dims = 0;
};

template<class _Ty>
Array<_Ty>::Array(_Ty* begin, _Ty* end)
{
	int n = end - begin;
	this->array = new _Ty * [1];
	this->array[0] = new _Ty[n];

	for (int i = 0; i < n; i++)
		this->array[0][i] = begin[i];

	shape[0] = 1;
	shape[1] = n;
};

template<class _Ty>
Array<_Ty>::Array(_Ty* arr, int n)
{
	this->array = new _Ty * [1];
	this->array[0] = new _Ty[n];

	for (int i = 0; i < n; i++)
		this->array[0][i] = arr[i];

	shape[0] = 1;
	shape[1] = n;
};

template<class _Ty>
Array<_Ty>::Array(_Ty** arr, int n, int m)
{
	this->array = new _Ty * [n];
	for (int i = 0; i < n; i++)
		this->array[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] = arr[i][j];

	shape[0] = n;
	shape[1] = m;
}

template<class _Ty>
Array<_Ty>::Array(int n)
{
	array = new _Ty * [1];
	array[0] = new _Ty[n];

	for (int i = 0; i < n; i++)
		array[0][i] = 0;

	shape[0] = 1;
	shape[1] = n;
};

template<class _Ty>
Array<_Ty>::Array(int n, int m)
{
	this->array = new _Ty * [n];
	for (int i = 0; i < n; i++)
		array[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] = 0;

	shape[0] = n;
	shape[1] = m;
}

template<class _Ty>
Array<_Ty>::Array(const Array<_Ty>& other) : array{nullptr}
{
	if (this == &other) return;

	int n, m;
	other.get_shape(n, m);

	/*if (this->shape[0] == n && this->shape[1] == m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				this->array[i][j] = other[i][j];
	}*/

	/*if (this->array)
	{
		for (int i = 0; i < this->shape[0]; i++)
			delete[] this->array[i];
		delete[] this->array;
	}*/

	this->array = new _Ty * [n];
	for (int i = 0; i < n; i++)
		this->array[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] = other[i][j];

	this->shape[0] = n;
	this->shape[1] = m;
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

template<class _Ty>
_Ty* Array<_Ty>::operator[](int i) const
{
	return array[i];
}

template<class _Ty>
Array<_Ty> Array<_Ty>::operator+(const Array<_Ty>& _arr) const
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];
		_Ty** arr = new _Ty * [n];
		for (int i = 0; i < n; i++)
			arr[i] = new _Ty[m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = this->array[i][j] + _arr[i][j];
		return Array<_Ty>{ arr, n, m };
	}
	return Array<_Ty>();
}

template<class _Ty>
template<class U>
Array<_Ty> Array<_Ty>::operator+(U num) const
{
	int n = this->shape[0];
	int m = this->shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = this->array[i][j] + static_cast<_Ty>(num);

	return Array<_Ty>{ arr, n, m };
}
;

template<class _Ty, class U>
Array<_Ty> operator+(U num, Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = static_cast<_Ty>(num) + _arr[i][j];

	return Array<_Ty>{ arr, n, m };
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
			this->array[i][j] -= static_cast<_Ty>(num);
	return *this;
}

template<class _Ty>
template<class U>
Array<_Ty> Array<_Ty>::operator*(U num) const
{
	int n = this->shape[0];
	int m = this->shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = this->array[i][j] * static_cast<_Ty>(num);

	return Array<_Ty>{ arr, n, m };
}

template<class _Ty>
Array<_Ty> Array<_Ty>::operator*(const Array<_Ty>& _arr) const
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];
		_Ty** arr = new _Ty * [n];
		for (int i = 0; i < n; i++)
			arr[i] = new _Ty[m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = this->array[i][j] * _arr[i][j];
		return Array<_Ty>{ arr, n, m };
	}
	return Array<_Ty>();
}

template<class _Ty>
Array<_Ty> Array<_Ty>::operator/(const Array<_Ty>& _arr) const
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];
		_Ty** arr = new _Ty * [n];
		for (int i = 0; i < n; i++)
			arr[i] = new _Ty[m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = this->array[i][j] / _arr[i][j];
		return Array<_Ty>{ arr, n, m };
	}
	return Array<_Ty>();
}

template<class _Ty>
template<class U>
Array<_Ty> Array<_Ty>::operator/(U num) const
{
	int n = this->shape[0];
	int m = this->shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = this->array[i][j] / static_cast<_Ty>(num);

	return Array<_Ty>{ arr, n, m };
}

template<class _Ty>
Array<_Ty>& Array<_Ty>::operator+=(const Array<_Ty>& _arr)
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
	return *this;
}

template<class _Ty>
Array<_Ty> Array<_Ty>::operator-() const
{
	int n = this->shape[0];
	int m = this->shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = -this->array[i][j];

	return Array<_Ty>{ arr, n, m };
}

template<class _Ty>
template<class U>
Array<_Ty>& Array<_Ty>::operator+=(U num)
{
	int n = this->shape[0];
	int m = this->shape[1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] += static_cast<_Ty>(num);
	return *this;
}

template<class _Ty>
template<class U>
Array<_Ty> Array<_Ty>::operator-(U num) const
{
	int n = this->shape[0];
	int m = this->shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = this->array[i][j] - static_cast<_Ty>(num);

	return Array<_Ty>{ arr, n, m };
}

template<class _Ty>
Array<_Ty> Array<_Ty>::operator-(const Array<_Ty>& _arr) const
{
	if (this->shape[0] == _arr.shape[0] && this->shape[1] == _arr.shape[1])
	{
		int n = this->shape[0];
		int m = this->shape[1];
		_Ty** arr = new _Ty * [n];
		for (int i = 0; i < n; i++)
			arr[i] = new _Ty[m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = this->array[i][j] - _arr[i][j];
		return Array<_Ty>{ arr, n, m };
	}
	return Array<_Ty>();
}

template<class _Ty>
Array<_Ty>& Array<_Ty>::operator-=(const Array<_Ty>& _arr)
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
	return *this;
}

template<class _Ty>
Array<_Ty>& Array<_Ty>::operator=(const Array<_Ty>& other)
{
	if (this == &other) return *this;

	int n, m;
	other.get_shape(n, m);
	
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


	this->array = new _Ty * [n];
	for (int i = 0; i < n; i++)
		this->array[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			this->array[i][j] = other[i][j];

	this->shape[0] = n;
	this->shape[1] = m;
	return *this;
}

template<class _Ty>
Array<_Ty> Array<_Ty>::dot(const Array<_Ty>& _arr) const
{
	int n1 = this->shape[0],
		m1 = this->shape[1],
		n2 = _arr.shape[0],
		m2 = _arr.shape[1];

	if (m1 == n2)
	{
		_Ty** arr = new _Ty * [n1];
		for (int i = 0; i < n1; i++)
			arr[i] = new _Ty[m2];

		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m2; j++)
			{
				_Ty sum = 0;
				for (int k = 0; k < m1; k++)
					sum += this->array[i][k] * _arr[k][j];
				arr[i][j] = sum;
			}

		return Array<_Ty>{arr, n1, m2};
	}

	return Array<_Ty>();
}

template<class _Ty>
Array<_Ty>& Array<_Ty>::T()
{
	static bool isFirst = true;
	static int n = this->shape[0];
	static int m = this->shape[1];
	static auto arr = new Array<_Ty>(m, n);

	if (isFirst)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				(*arr)[j][i] = this->array[i][j];
		isFirst = false;
	}

	return *arr;
}

template<class _Ty>
void Array<_Ty>::get_shape(int& n, int& m) const
{
	n = this->shape[0];
	m = this->shape[1];
}

template<class _Ty>
void Array<_Ty>::rand_uniform(_Ty min, _Ty max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(min, max);
	for (int i = 0; i < shape[0]; i++)
		for (int j = 0; j < shape[1]; j++)
			array[i][j] = dist(gen);
};

template<class _Ty>
std::ostream& operator<<(std::ostream& os, const Array<_Ty>& array)
{
	for (int i = 0; i < array.shape[0]; i++)
	{
		for (int j = 0; j < array.shape[1]; j++)
			os << std::setiosflags(std::ios::left)
			<< std::setw(10) << array[i][j];
		os << '\n';
	}
	return os;
}

template<class _Ty, class U>
Array<_Ty> operator-(U num, Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = static_cast<_Ty>(num) - _arr[i][j];

	return Array<_Ty>{ arr, n, m };
}

template<class _Ty, class U>
Array<_Ty> operator*(U num, const Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = _arr[i][j] * static_cast<_Ty>(num);

	return Array<_Ty>{ arr, n, m };
}

template<class _Ty, class U>
Array<_Ty> operator/(U num, Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = static_cast<_Ty>(num) / _arr[i][j];

	return Array<_Ty>{ arr, n, m };
}

template<class _Ty = double, class U>
Array<_Ty> rand_uniform(U min, U max, int n)
{
	Array<_Ty> array{ n };
	array.rand_uniform(static_cast<_Ty>(min), static_cast<_Ty>(max));
	return array;
}

template<class _Ty = double, class U>
Array<_Ty> rand_uniform(U min, U max, int n, int m)
{
	Array<_Ty> array{ n, m };
	array.rand_uniform(static_cast<_Ty>(min), static_cast<_Ty>(max));
	return array;
}

template<class _Ty>
Array<_Ty> dot(const Array<_Ty>& arr1, const Array<_Ty>& arr2)
{
	return arr1.dot(arr2);
}

template<class _Ty>
Array<_Ty> exponent(const Array<_Ty>& _arr)
{
	int n = _arr.shape[0];
	int m = _arr.shape[1];
	_Ty** arr = new _Ty * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new _Ty[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = exp(_arr.array[i][j]);

	return Array<double>{arr, n, m};
}