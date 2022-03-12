#include "Perceptron.h"

Perceptron::Perceptron() : 
	name(""), quantity(0), a(1), data(Array<double>{}), labels(Array<double>{})
{
}

//Perceptron::Perceptron(std::string& name, double learning_speed, long long quantity) : name(name), a(learning_speed), quantity(quantity), data(Array<double>{}), labels(Array<double>{})
//{
//}
//
//Perceptron::Perceptron(const char* name, double learning_speed, long long quantity) : name(name), a(learning_speed), quantity(quantity), data(Array<double>{}), labels(Array<double>{})
//{
//}

Perceptron::Perceptron(std::string& name, double learning_speed, long long quantity, const Array<double>& data, const Array<double>& labels)
	: name(name), a(learning_speed), quantity(quantity), data(data), labels(labels)
{
}

Perceptron::Perceptron(const char* name, double learning_speed, long long quantity, const Array<double>& data, const Array<double>& labels)
	: name(name), a(learning_speed), quantity(quantity), data(data), labels(labels)
{
}

void Perceptron::addLayer(int size, Array<double>(*activation_function)(const Array<double>& x, Array<double>& der))
{
	auto layer = new Layer {size, activation_function};
	this->layers.push_back(*layer);
}

void Perceptron::init()
{
	if (this->layers.size())
	{
		auto layer = &layers.front();
		int n, m;
		data.get_shape(n, m);

		do
		{
			layer->el.set_weights(m);
			m = layer->el.get_size();
		} while (layer = layer->next);
	}
}

std::ostream& operator<<(std::ostream& os, const Perceptron& perc)
{
	os << perc.layers;
	return os;
}
