#include <iostream>
#include <fstream>
#include "Perceptron.h"

const int N = 1000;

int& add(int& a, int& b);

int main()
{
	double** _data1 = new double* [N];
	for (size_t i = 0; i < N; i++)
		_data1[i] = new double[28*28];

	double** _answ = new double* [N];
	for (int i = 0; i < N; i++)
		_answ[i] = new double[10];

	std::ifstream in{ "mnist_train.csv" };
	
	for (int i = 0; i < N; i++)
	{
		int n;
		char delim;
		in >> n;
		for (int j = 0; j < 10; j++)
			_answ[i][j] = 0;
		_answ[i][n] = 1;

		for (int j = 0; j < 28*28; j++)
		{
			in >> delim;
			in >> _data1[i][j];
		}
	}



	Array<double> data{ _data1, N, 28*28 };
	Array<double> answ{ _answ, N, 10 };
	in.close();

	data = data / 255;
	std::cout << std::flush;

	Perceptron perc{"Test", 0.1, 101, data, answ};
	perc.addLayer(256, ActFunc::ReLU);
	perc.addLayer(10, ActFunc::sigmoid);

	perc.init();

	perc.start();

	/*int a = 6, b = 8;
	int& d = add(a, b);
	std::cout << &d << '\n';
	std::cout << d;*/
	
	return 0;

}

int& add(int& a, int& b)
{
	int c = a + b;
	std::cout << &c << '\n';
	return c;
}
