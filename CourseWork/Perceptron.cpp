#include "Perceptron.h"

Perceptron::Perceptron() :
	name(""),
	quantity(0),
	a(1),
	data(Array<double>{}),
	labels(Array<double>{}),
	batch(0)
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

Perceptron::Perceptron(std::string& file_name) :
	quantity(0),
	a(1),
	data(Array<double>{}),
	labels(Array<double>{}),
	batch(0)
{
	int layers_number;
	std::fstream in(file_name, std::ios::in | std::ios::binary);
	in >> this->name;
	in >> layers_number;

	for (int i = 0; i < layers_number; i++)
	{
		auto layer = new Layer(in);
		if (this->layers.size())
			this->layers.end().el.next = layer;

		this->layers.push_back(*layer);
	}
}

Array<double> Perceptron::operator()(const Array<double>& input)
{
	auto output = this->layers.begin().el.activation(input);
	return output;
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
			this->layers.begin().el.back_propagation(delta);

			error += sqrt(sum(delta ^ 2) / delta.shape[1]);
			if (i % this->batch == 0)
			{
				std::cout << _ << '.' << i / this->batch << ": " << error / this->batch << '\n' << std::flush;
				error = 0;
			}
		}
	}
}

void Perceptron::save()
{
	std::fstream out(this->name + ".txt", std::ios::out | std::ios::binary);
	out << this->name + '\n';
	out << this->layers.size() << '\n';

	for (auto layer = &this->layers.begin(); layer != nullptr; layer = layer->next)
		layer->el.save(out);
	out.close();
}

std::ostream& operator<<(std::ostream& os, const Perceptron& perc)
{
	os << perc.layers;
	return os;
}
