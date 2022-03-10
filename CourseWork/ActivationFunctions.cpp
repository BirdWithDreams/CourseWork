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
	Array<T> tanh(const Array<T>& x)
	{
		auto x1 = x * 2;
		auto x2 = exponent(x1);
		auto x3_1 = x2 - 1;
		auto x3_2 = x2 + 1;
		auto res = x3_1 / x3_2;
		return res;
	}
}