#include <iostream>
#include "Perceptron.h"

int main()
{
	Perceptron perc;
	Layer<double> layer{5, ActFunc::sigmoid<double> };

	return 0;
}