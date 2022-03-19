#include "Layer.h"

Layer::Layer(int size, Array<double>(*func)(const Array<double>& x, Array<double>& der), double learn_speed) :
	size(size),
	func(func),
	a(learn_speed)
{
	this->neurons = Array<double>(size);
	this->derivative = Array<double>(size);
	this->displacement_vector = rand_uniform(-0.01, 0.01, this->size);
}

Layer::Layer(const Layer& other) :
	size(other.size),
	neurons(other.neurons),
	derivative(other.derivative),
	weights(other.weights),
	displacement_vector(other.displacement_vector),
	a(other.a)
{
	this->func = other.func;
}

Layer::Layer(std::fstream& fio)
{
	std::string func_name;
	fio >> func_name;
	this->func = ActFunc::get_function<double>(func_name);

	fio.seekg(std::ios::cur, 1);
	this->weights = Array<double>(fio);
	this->displacement_vector = Array<double>(fio);

	this->size = this->weights.shape[1];
	this->neurons = Array<double>(this->size);
	this->derivative = Array<double>(this->size);

	fio.seekg(std::ios::cur, 1);
}

void Layer::set_weights(int _size)
{
	weights = rand_uniform(-0.01, 0.01, _size, this->size);
}

int Layer::get_size()
{
	return this->size;
}

void Layer::save(std::string& name)
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

void Layer::save(std::fstream& out)
{
	std::string func_name = ActFunc::get_name(this->func);
	out << func_name << ' ';
	this->weights.save(out);
	this->displacement_vector.save(out);
	out << '\n';
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
	this->weights -= this->a * this->input.T().dot(_delta);
	this->displacement_vector -= this->a * _delta;

	return _del;
}

std::ostream& operator<<(std::ostream& os, const Layer& layer)
{
	os << layer.weights;
	return os;
}

