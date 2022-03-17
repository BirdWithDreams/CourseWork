#include "Layer.h"

Layer::Layer(int size, Array<double>(*func)(const Array<double>& x, Array<double>& der)) :
	size(size),
	func(func)
{
	this->neurons = Array<double>(size);
	this->derivative = Array<double>(size);
	this->displacement_vector = rand_uniform(-0.1, 0.1, this->size);
}

Layer::Layer(const Layer& other) :
	size(other.size),
	neurons(other.neurons),
	derivative(other.derivative),
	weights(other.weights),
	displacement_vector(other.displacement_vector)
{
	this->func = other.func;
}

void Layer::set_weights(int _size)
{
	weights = rand_uniform(-0.1, 0.1, _size, this->size);
}

int Layer::get_size()
{
	return this->size;
}

void Layer::save(std::string& name)
{
	std::ofstream out{ name + ".txt"};
	for (int i = 0; i < this->weights.shape[0]; i++)
	{
		for (int j = 0; j < weights.shape[1]; j++)
			out << this->weights[i][j] << ' ';
		out << '\n';
	}
	for (int i = 0; i < this->displacement_vector.shape[1]; i++)
		out << this->displacement_vector[0][i] << ' ';
	out.close();

}

void Layer::save(std::string&& name)
{
	std::ofstream out{ name + ".txt" };
	for (int i = 0; i < this->weights.shape[0]; i++)
	{
		for (int j = 0; j < weights.shape[1]; j++)
			out << this->weights[i][j] << ' ';
		out << '\n';
	}
	for (int i = 0; i < this->displacement_vector.shape[1]; i++)
		out << this->displacement_vector[0][i] << ' ';
	out.close();
}

Array<double> Layer::activation(const Array<double>& input)
{
	this->input = input;
	auto _n = this->displacement_vector + dot(this->input, this->weights);

	this->neurons = this->func(_n, this->derivative);

	if (this->next)
		return this->next->activation(this->neurons);

	else
		return this->neurons;
}

Array<double> Layer::back_propagation(const Array<double>& delta)
{
	Array<double> _delta;
	if (this->next)
		_delta = this->derivative * this->next->back_propagation(delta);
	else
		_delta = this->derivative * delta;

	auto _del = _delta.dot(this->weights.T());
	this->weights -= 0.1 * this->input.T().dot(_delta);
	this->displacement_vector -= 0.1 * _delta;

	return _del;
}

std::ostream& operator<<(std::ostream& os, const Layer& layer)
{
	os << layer.weights;
	return os;
}
