#include "exceptions.h"

BaseException::BaseException()
{
	text = "";
}

BaseException::BaseException(std::string _text)
{
	text = _text;
}

std::string BaseException::what() const
{
	return text;
}

ValueError::ValueError() : BaseException()
{
	text = "ValueError: operand has an invalid value";
}

ValueError::ValueError(std::string _text) : BaseException("ValueError: " + _text)
{
}

MatMulError::MatMulError() : ValueError("matmul: can't multiply matrixes.")
{
}

MatMulError::MatMulError(std::string _text) : ValueError("matmul: " + _text)
{
}

MatMulError::MatMulError(int n, int m) : ValueError("matmul: ")
{
	text += "can't multiply matrixes (size " + std::to_string(n) + "is different from " + std::to_string(m) + ")";
}

ShapeError::ShapeError() : ValueError("shape error.")
{
}

ShapeError::ShapeError(std::string _text) : ValueError("shape error: " + _text)
{
}

ShapeError::ShapeError(int n1, int m1, int n2, int m2) :ShapeError("")
{
	text += "operands could not be broadcast together with shapes (" +
		std::to_string(n1) + ", " + std::to_string(m1) + ") and (" + 
		std::to_string(n2) + ", " + std::to_string(m2) + ")";
}

IndexError::IndexError() : BaseException("IndexError: index out of range")
{
}

AttributeError::AttributeError(std::string _text) : BaseException("AttributeError: " + _text)
{
}

FileError::FileError(std::string file_name) : BaseException("FileError: no such file or directory: " + file_name)
{
}
