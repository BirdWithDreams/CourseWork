#include "Perceptron.h"

Perceptron::Perceptron() : 
	name(""), quantity(0), a(1), data(Array<double>{}), labels(Array<double>{}), first_layer_size(0)
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
	: name(name), a(learning_speed), quantity(quantity), data(data), labels(labels), first_layer_size(0)
{
}

Perceptron::Perceptron(const char* name, double learning_speed, long long quantity, const Array<double>& data, const Array<double>& labels)
	: name(name), a(learning_speed), quantity(quantity), data(data), labels(labels), first_layer_size(0)
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
		data.get_shape(n, this->first_layer_size);
		m = this->first_layer_size;
		do
		{
			layer->el.set_weights(m);
			m = layer->el.get_size();
		} while (layer = layer->next);
	}
}

void Perceptron::start()
{
	for (int i = 0; i < this->quantity; i++)
	{
		auto input = Array<double>{ this->data[i], this->first_layer_size };
		for (auto layer = &this->layers.front(); layer != nullptr; layer = layer->next)
		{
			input = layer->el.activation(input);
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Perceptron& perc)
{
	os << perc.layers;
	return os;
}
