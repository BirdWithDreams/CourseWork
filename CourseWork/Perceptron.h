#pragma once
#include <string>

#include "Layer.h"

#include "LinkedList.h"
#include "LinkedList.cpp"

class Perceptron
{
	friend std::ostream& operator<<(std::ostream& os, const Perceptron& perc);

public:
	Perceptron();
	/*Perceptron(std::string& name, double learning_speed, long long quantity);
	Perceptron(const char* name, double learning_speed, long long quantity);*/

	Perceptron(std::string& name, double learning_speed, long long quantity, const Array<double>& data, const Array<double>& labels);
	Perceptron(const char* name, double learning_speed, long long quantity, const Array<double>& data, const Array<double>& labels);

	void addLayer(int size, Array<double>(*activation_function)(const Array<double>& x, Array<double>& der));
	void init();

private:
	std::string name;
	double a;
	long long quantity;

	LinkedList<Layer> layers;

	const Array<double>& data;
	const Array<double>& labels;
};

