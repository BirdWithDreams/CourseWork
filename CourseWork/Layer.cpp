#include "Layer.h"

template<class _Ty>
Layer< _Ty>::Layer(int size, Array<_Ty>(*func)(const Array<_Ty>& x, Array<_Ty>& der)) :
	size(size),
	func(func)
{
}
