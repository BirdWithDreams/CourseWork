#pragma once
#include "Array.h"
#include "Array.cpp"

namespace ActFunc
{
	template<class T>
	Array<T> sigmoid(const Array<T>& x);

	template<class T>
	Array<T> tanh(const Array<T>& x);

	template<class T>
	Array<T> ReLU(const Array<T>& x);
}
