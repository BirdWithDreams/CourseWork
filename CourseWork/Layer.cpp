#include "Layer.h"

Layer::Layer(int size, Array<double>(*func)(const Array<double>& x, Array<double>& der)) :
	size(size),
	func(func)
{
	this->neurons = Array<double>(size);
	this->derivative = Array<double>(size);
}
