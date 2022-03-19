#include "Perceptron.h"

Perceptron::Perceptron() :
	name(""),
	quantity(0),
	a(1),
	data(Array<double>{}),
	labels(Array<double>{}),
	batch(batch)
{
}

Perceptron::Perceptron(std::string& name, double learning_speed, long long quantity, const Array<double>& data, const Array<double>& labels, int batch) :
	name(name),
	a(learning_speed),
	quantity(quantity),
	data(data),
	labels(labels),
	batch(batch)
{
}

Perceptron::Perceptron(const char* name, double learning_speed, long long quantity, const Array<double>& data, const Array<double>& labels, int batch) :
	name(name),
	a(learning_speed),
	quantity(quantity),
	data(data),
	labels(labels),
	batch(batch)
{
}

void Perceptron::addLayer(int size, Array<double>(*activation_function)(const Array<double>& x, Array<double>& der))
{
	auto layer = new Layer{ size, activation_function, this->a };
	if (this->layers.size())
		this->layers.end().el.next = layer;

	this->layers.push_back(*layer);
}

void Perceptron::init()
{
	if (this->layers.size())
	{
		auto layer = &layers.begin();
		int 
			n = data.shape[0],
			m = data.shape[1];
		do
		{
			layer->el.set_weights(m);
			m = layer->el.get_size();
		} while (layer = layer->next);
	}
}

void Perceptron::start()
{
	double error = 0;
	for (int _ = 0; _ < this->quantity; _++)
	{
		for (int i = 0; i < this->data.shape[0]; i++)
		{
			auto input = Array<double>{ this->data[i], this->data.shape[1] };
			auto output = layers.begin().el.activation(input);

			auto delta = output - Array<double>{ this->labels[i], this->labels.shape[1] };
			error += sqrt(sum(delta ^ 2) / delta.shape[1]);

			this->layers.begin().el.back_propagation(delta);

			if (i % 100 == 0)
			{
				std::cout << _ << '.' << i / 100 << ": " << error / 100 << '\n' << std::flush;
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
