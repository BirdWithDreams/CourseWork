#include <iostream>
#include "Perceptron.h"

int main()
{
	auto data = rand_uniform(0, 10, 5);
	auto labels = rand_uniform(0, 10, 5);
	Perceptron perc{"Test", 0.01, 100, data, labels};
	perc.addLayer(10, ActFunc::sigmoid);
	perc.addLayer(20, ActFunc::sigmoid);
	perc.addLayer(1, ActFunc::sigmoid);

	perc.init();

	perc.start();
	return 0;

}