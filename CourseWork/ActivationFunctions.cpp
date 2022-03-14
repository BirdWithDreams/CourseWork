#include "ActivationFunctions.h"

namespace ActFunc
{
	template<class T>
	Array<T> sigmoid(const Array<T>& x)
	{
		auto x1 = -x;
		auto x2 = exponent(x1) + 1;
		auto res = 1 / x2;
		return res;
	}

	template<class T>
	Array<T> sigmoid(const Array<T>& x, Array<T>& der)
	{
		auto res = sigmoid(x);
		auto res1 = 1 - res;
		der = res * res1;

		return res;
	}

	template<class T>
	Array<T> tanh(const Array<T>& x)
	{
		int
			n = x.shape[0],
			m = x.shape[1];

		auto arr = new T * [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new T[m];
			for (int j = 0; j < m; j++)
				arr[i][j] = ::tanh(x[i][j]);
		}

		Array<T> res{ arr, n, m };
		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;

		return res;
	}

	template<class T>
	Array<T> tanh(const Array<T>& x, Array<T>& der)
	{
		auto res = tanh(x);
		auto _der = res * res;
		der = 1 - _der;
		return res;
	}

	template<class T>
	Array<T> ReLU(Array<T>& x)
	{
		int n, m;
		x.get_shape(n, m);
		Array<T> res{ n, m };

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (x[i][j] > 0)
					res[i][j] = x[i][j];

		return res;
	}
	template<class T>
	Array<T> ReLU(const Array<T>& x, Array<T>& der)
	{
		int n, m;
		x.get_shape(n, m);
		Array<T> res{ n, m };
		Array<T> _der{ n, m };

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (x[i][j] > 0)
				{
					res[i][j] = x[i][j];
					_der[i][j] = 1;
				}
		der = _der;
		return res;
	}

	template<class T>
	Array<T> softmax(const Array<T>& x)
	{
		auto res = exponent(x);
		return res/sum(res);
	}

	template<class T>
	Array<T> softmax(const Array<T>& x, Array<T>& der)
	{
		auto res = softmax(x);
		der = Array<T>{ x.shape[0], x.shape[1] };
		for (int i = 0; i < x.shape[0]; i++)
			for (int j = 0; j < x.shape[1]; j++)
				der[i][j] = 1 / x.shape[1];

		return res;
	}
}