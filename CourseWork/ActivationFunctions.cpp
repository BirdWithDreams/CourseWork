#include "ActivationFunctions.h"

namespace ActFunc
{
	template<class T>
	Array<T> sigmoid(const Array<T>& x)
	{
		auto x1 = -x;
		auto x2 = exponent(x) + 1;
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
		auto x1 = x * 2;
		auto x2 = exponent(x1);
		auto x3_1 = x2 - 1;
		auto x3_2 = x2 + 1;
		auto res = x3_1 / x3_2;
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
}