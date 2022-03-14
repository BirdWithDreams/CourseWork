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
	if (this->layers.size())
		this->layers.end().el.next = layer;

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
		double error = 0;
		for (int i = 0; i < this->data.shape[0]; i++)
		{
			auto input = Array<double>{ this->data[i], this->data.shape[1] };
			auto output = layers.begin().el.activation(input);

			auto delta = output - Array<double>{ this->labels[i], this->labels.shape[1] };
			error += sqrt(sum(delta ^ 2) / delta.shape[1]);

			this->layers.begin().el.back_propagation(delta);

			if (i % 100 == 0)
			{
				std::cout << _ << '.' << i / 100 << ": " << error / 100 << '\n';
				std::cout << "Output: " << output << '\n';
				error = 0;
			}
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Perceptron& perc)
{
	os << perc.layers;
	return os;
}
