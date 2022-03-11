#pragma once

template<class _El>
class Node
{
public:
	_El& el;
	Node* next = nullptr;

	Node(_El& el);
};

