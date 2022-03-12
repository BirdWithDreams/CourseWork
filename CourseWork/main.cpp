#include <iostream>
#include "Perceptron.h"

int main()
{
	Perceptron perc{"Test", 0.01, 100};
	perc.addLayer(10, ActFunc::sigmoid);

	return 0;
}