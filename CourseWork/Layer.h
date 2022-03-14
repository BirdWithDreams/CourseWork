#pragma once
#include "ActivationFunctions.h"
#include "ActivationFunctions.cpp"

class Layer
{
	friend std::ostream& operator<<(std::ostream& os, const Layer& layer);

private:
	int size;

	Array<double> weights;
	Array<double> displacement_vector;
	Array<double> neurons;
	Array<double> derivative;
	Array<double> input;

	Array<double>(*func)(const Array<double>& x, Array<double>& der);

public:
	Layer(int size, Array<double>(*func)(const Array<double>& x, Array<double>& der));
	Layer(const Layer& other);

	void set_weights(int _size);
	int get_size();

	Array<double> activation(const Array<double>& input);
	Array<double> back_propagation(const Array<double>& delta);
};

