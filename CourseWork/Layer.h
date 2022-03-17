#pragma once
#include <fstream>

#include "ActivationFunctions.h"
#include "ActivationFunctions.cpp"

class Layer
{
	friend std::ostream& operator<<(std::ostream& os, const Layer& layer);

public:
	Layer* next = nullptr;

private:
	int size;
	double a;

	Array<double> weights;
	Array<double> displacement_vector;
	Array<double> neurons;
	Array<double> derivative;
	Array<double> input;

	Array<double>(*func)(const Array<double>& x, Array<double>& der);

public:
	Layer(
		int size, 
		Array<double>(*func)(const Array<double>& x, 
		Array<double>& der), double learn_speed
	);

	Layer(const Layer& other);

	void set_weights(int _size);
	int get_size();
	void save(std::string& name);
	void save(std::string&& name);

	Array<double> activation(const Array<double>& input);
	Array<double> back_propagation(const Array<double>& delta);
};

