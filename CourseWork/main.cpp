#include <iostream>
#include <fstream>
#include "Perceptron.h"

const int N = 1000;

int main()
{
	std::ifstream in{ "mnist_train.csv" };
	Array<double> data{ N, 28 * 28 };
	auto answ = zeros<double>(N, 10);

	for (int i = 0; i < N; i++)
	{
		int n;
		char delim;
		in >> n;
		answ[i][n] = 1;

		for (int j = 0; j < 28 * 28; j++)
		{
			in >> delim;
			in >> data[i][j];
		}
	}

	in.close();

	data = data / 255;
	std::cout << std::flush;

	Perceptron perc{ "Test", 0.1, 1000, data, answ };
	perc.addLayer(200, ActFunc::tanh);
	perc.addLayer(10, ActFunc::softmax);

	perc.init();

	perc.start();

	return 0;

}
