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

Array<double> Layer::activation(const Array<double>& input)
{
	this->input = input;
	auto _n = dot(this->input, this->weights);
	_n += this->displacement_vector;

	this->neurons = this->func(_n, this->derivative);
	return this->neurons;
}

Array<double> Layer::back_propagation(const Array<double>& delta)
{
	auto _delta = this->derivative * delta;
	auto _del = _delta.dot(this->weights.T());
	this->weights -= 0.01 * this->input.T().dot(_delta);
	this->displacement_vector -= 0.01 * _delta;

	return _del;

}

std::ostream& operator<<(std::ostream& os, const Layer& layer)
{
	os << layer.weights;
	return os;
}
