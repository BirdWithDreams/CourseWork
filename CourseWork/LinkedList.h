#pragma once
#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include "exceptions.h"

template<class _El>
class LinkedList
{
	template<class _El>
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<_El>& list);

	using element         = _El;
	using pointer         = typename _El*;
	using reference       = _El&;
	using const_reference = const reference;

	using node           = Node<_El>;
	using node_pointer   = Node<_El>*;
	using node_reference = Node<_El>&;

private:
	int cur_size = 0;
	node_pointer
		head = nullptr,
		tail = nullptr;

public:
	bool push_back(const_reference el);
	reference pop_back();

	node_reference begin();
	node_reference end();

	int size();
};
