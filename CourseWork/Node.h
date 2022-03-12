#pragma once

template<class _El>
class Node
{
public:
	_El& el;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node(_El& el);
};

