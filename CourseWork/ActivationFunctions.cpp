#include "ActivationFunctions.h"

namespace ActFunc
{
	template<class T>
	Array<T> sigmoid(const Array<T>& x)
	{
		auto x1 = -x;
		auto x2 = exponent(x1) + 1;
		auto res = 1 / x2;
		return res;
	}

	template<class T>
	Array<T> sigmoid(const Array<T>& x, Array<T>& der)
	{
		auto res = sigmoid(x);
		auto res1 = 1 - res;
		der = res * res1;

		return res;
	}

	template<class T>
	Array<T> tanh(const Array<T>& x)
	{
		int
			n = x.shape[0],
			m = x.shape[1];

		Array<T> res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = ::tanh(x[i][j]);

		return res;
	}

	template<class T>
	Array<T> tanh(const Array<T>& x, Array<T>& der)
	{
		auto res = tanh(x);
		auto _der = res * res;
		der = 1 - _der;
		return res;
	}

	template<class T>
	Array<T> ReLU(Array<T>& x)
	{
		int
			n = x.shape[0],
			m = x.shape[1];
		auto res = zeros<double>(n, m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (x[i][j] > 0)
					res[i][j] = x[i][j];

		return res;
	}
	template<class T>
	Array<T> ReLU(const Array<T>& x, Array<T>& der)
	{
		int 
			n = x.shape[0],
			m = x.shape[1];
		auto res = zeros<double>(n, m);
		auto _der = zeros<double>(n, m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (x[i][j] > 0)
				{
					res[i][j] = x[i][j];
					_der[i][j] = 1;
				}
		der = _der;
		return res;
	}

	template<class T>
	Array<T> softmax(const Array<T>& x)
	{
		auto res = exponent(x);
		return res / sum(res);
	}

	template<class T>
	Array<T> softmax(const Array<T>& x, Array<T>& der)
	{
		auto res = softmax(x);
		Array<T> _der{ x.shape[0], x.shape[1] };
		for (int i = 0; i < x.shape[0]; i++)
			for (int j = 0; j < x.shape[1]; j++)
				_der[i][j] = 1.0 / x.shape[1];

		der = _der;

		return res;
	}

	template<class T>
	std::string get_name(Array<T>(*func)(const Array<T>& x, Array<T>& der))
	{
		static Array<double>(*_sigmoid)(const Array<double>&x, Array<double>&der) = ActFunc::sigmoid;
		static Array<double>(*_tanh)(const Array<double>&x, Array<double>&der) = ActFunc::tanh;
		static Array<double>(*_ReLU)(const Array<double>&x, Array<double>&der) = ActFunc::ReLU;
		static Array<double>(*_softmax)(const Array<double>&x, Array<double>&der) = ActFunc::softmax;

		if (func == _sigmoid)
			return std::string("sigmoid");
		if (func == _tanh)
			return std::string("tanh");
		if (func == _ReLU)
			return std::string("ReLU");
		if (func == _softmax)
			return std::string("softmax");
	}

	template<class T>
	Array<T>(*get_function(std::string& name))(const Array<T>& x, Array<T>& der)
	{
		if (name == "sigmoid") return sigmoid;
		if (name == "tanh") return tanh;
		if (name == "ReLU") return ReLU;
		if (name == "softmax") return softmax;

		return nullptr;
	}
}