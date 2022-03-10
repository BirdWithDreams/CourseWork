#pragma once
#include "Array.h"
#include "Array.cpp"

namespace ActFunc
{
	template<class T>
	Array<T> sigmoid(const Array<T>& x);

	template<class T>
	Array<T> sigmoid(const Array<T>& x, Array<T>& der);

	template<class T>
	Array<T> tanh(const Array<T>& x);

	template<class T>
	Array<T> ReLU(Array<T>& x);
}
