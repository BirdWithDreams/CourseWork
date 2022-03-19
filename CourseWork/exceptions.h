#pragma once
#include <string>

class BaseException
{
public:
	BaseException();
	BaseException(std::string _text);

	std::string what() const;

protected:
	std::string text;
};

class ValueError : public BaseException
{
public:
	ValueError();
	ValueError(std::string _text);
};

class MatMulError : public ValueError
{
public:
	MatMulError();
	MatMulError(std::string _text);
	MatMulError(int n, int m);
};

class ShapeError : public ValueError
{
public:
	ShapeError();
	ShapeError(std::string _text);
	ShapeError(int n1, int m1, int n2, int m2);
};

class IndexError : public BaseException
{
public:
	IndexError();
};

class AttributeError : public BaseException
{
public:
	AttributeError(std::string _text);
};

class FileError : public BaseException
{
public:
	FileError(std::string file_name);
};