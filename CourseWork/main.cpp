#include <iostream>
#include <fstream>
#include "Perceptron.h"

const int N = 3000;

int& add(int& a, int& b);

int main()
{
	/*double** _data1 = new double* [N];
	for (size_t i = 0; i < N; i++)
		_data1[i] = new double[28*28];

	double** _answ = new double* [N];
	for (int i = 0; i < N; i++)
		_answ[i] = new double[10];

	std::ifstream in{ "mnist_train.csv" };
	Array<double> data{ N, 28*28 };
	Array<double> answ{ N, 10 };
	
	for (int i = 0; i < N; i++)
	{
		int n;
		char delim;
		in >> n;
		answ[i][n] = 1;

		for (int j = 0; j < 28*28; j++)
		{
			in >> delim;
			in >> data[i][j];
		}
	}



	in.close();

	data = data / 255;
	std::cout << std::flush;

	Perceptron perc{"Test", 0.1, 1000, data, answ};
	perc.addLayer(200, ActFunc::tanh);
	perc.addLayer(10, ActFunc::softmax);

	perc.init();

	perc.start();*/

	auto arr = rand_uniform(-0.1, 0.1, 5);
	std::cout << arr;
	
	return 0;

}

int& add(int& a, int& b)
{
	int c = a + b;
	std::cout << &c << '\n';
	return c;
}
