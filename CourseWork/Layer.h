#pragma once
#include "ActivationFunctions.h"
#include "ActivationFunctions.cpp"

template<class _Ty>
class Layer
{
private:
	int size;

	Array<_Ty> weights;
	Array<_Ty> neurons;
	Array<_Ty> derivative;

	Array<_Ty>(*func)(Array<_Ty>& x, Array<_Ty>& der);

public:
	Layer(int size, Array<_Ty>(*func)(const Array<_Ty>& x, Array<_Ty>& der));
};

