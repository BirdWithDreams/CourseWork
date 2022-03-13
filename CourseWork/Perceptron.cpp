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
		auto layer = &layers.begin();
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
	for (int _ = 0; _ < this->quantity; _++)
	{
		for (int i = 0; i < this->data.shape[0]; i++)
		{
			//std::cout << std::endl;
			auto output = Array<double>{ this->data[i], this->data.shape[1] };
			for (auto layer = &this->layers.begin(); layer != nullptr; layer = layer->next)
				output = layer->el.activation(output);

			auto delta = output - Array<double>{ this->labels[i], this->labels.shape[1] };
			std::cout<< delta;
			for (auto layer = &this->layers.end(); layer != nullptr; layer = layer->prev)
				delta = layer->el.back_propagation(delta);

		}
	}
}

std::ostream& operator<<(std::ostream& os, const Perceptron& perc)
{
	os << perc.layers;
	return os;
}
