#pragma once
#include "ActivationFunctions.h"
#include "ActivationFunctions.cpp"

class Layer
{
private:
	int size;

	Array<double> weights;
	Array<double> neurons;
	Array<double> derivative;

	Array<double>(*func)(const Array<double>& x, Array<double>& der);

public:
	Layer(int size, Array<double>(*func)(const Array<double>& x, Array<double>& der));
};

