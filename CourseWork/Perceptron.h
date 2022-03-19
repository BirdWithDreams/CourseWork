#pragma once
#include <string>

#include "Layer.h"

#include "LinkedList.h"
#include "LinkedList.cpp"

class Perceptron
{
	friend std::ostream& operator<<(std::ostream& os, const Perceptron& perc);

public:
private:
	std::string name;
	double a;
	long long quantity;
	int batch;

	int first_layer_size;
	LinkedList<Layer> layers;

	const Array<double>& data;
	const Array<double>& labels;
public:
	Perceptron();

	Perceptron(std::string& name, double learning_speed, long long quantity, const Array<double>& data, const Array<double>& labels, int batch = 100);
	Perceptron(const char* name, double learning_speed, long long quantity, const Array<double>& data, const Array<double>& labels, int batch = 100);

	Perceptron(std::string& file_name);
	void init();
	void start();

	void save();
};

