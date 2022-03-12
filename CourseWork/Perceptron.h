#pragma once
#include <string>

#include "Layer.h"
#include "Layer.cpp"

#include "LinkedList.h"
#include "LinkedList.cpp"

class Perceptron
{
public:
	Perceptron();
	Perceptron(std::string& name, double learning_speed, long long quantity);
	Perceptron(const char* name, double learning_speed, long long quantity);

	void addLayer(int size, Array<double>(*activation_function)(const Array<double>& x, Array<double>& der));

private:
	std::string name;
	double a;
	long long quantity;

	LinkedList<Layer<double>> layers;
};

