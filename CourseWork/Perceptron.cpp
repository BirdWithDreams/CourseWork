#include "Perceptron.h"

Perceptron::Perceptron() : name(""), quantity(0), a(1)
{
}

Perceptron::Perceptron(std::string& name, double learning_speed, long long quantity) : name(name), a(learning_speed), quantity(quantity)
{
}

Perceptron::Perceptron(const char* name, double learning_speed, long long quantity) : name(name), a(learning_speed), quantity(quantity)
{
}

void Perceptron::addLayer(int size, Array<double>(*activation_function)(const Array<double>& x, Array<double>& der))
{
	Layer<double> layer{size, activation_function};
	layers.push_back(layer);
}
