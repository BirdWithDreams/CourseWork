#include "ActivationFunctions.h"

template<class T>
Array<T> sigmoid(const Array<T>& x)
{
	auto res = 1 / (exponent(-x) + 1);
	return res;
}