#include "Layer.h"

Layer::Layer(int size, Array<double>(*func)(const Array<double>& x, Array<double>& der)) :
	size(size),
	func(func)
{
	this->neurons = Array<double>(size);
	this->derivative = Array<double>(size);
}

Layer::Layer(const Layer& other) : 
	size(other.size),
	neurons(other.neurons),
	derivative(other.derivative),
	weights(other.weights)
{
	this->func = other.func;
}

void Layer::set_weights(int _size)
{
	weights = rand_uniform(-0.01, 0.01, _size, this->size);
}

int Layer::get_size()
{
	return this->size;
}

std::ostream& operator<<(std::ostream& os, const Layer& layer)
{
	os << layer.weights;
	return os;
}
