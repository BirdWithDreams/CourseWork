#pragma once
#include <iostream>
#include "Node.h"
#include "Node.cpp"
//#include "exceptions.h"

template<class _El>
class LinkedList
{
	template<class _El>
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<_El>& list);

private:
	int cur_size = 0;
	Node<_El>
		* head = nullptr,
		* tail = nullptr;

public:
	bool push_back(_El& el);
	_El& pop_back();

	Node<_El>& begin();
	Node<_El>& end();

	/*bool push_front(_El& el);
	_El& pop_front();*/

	//_El get(int index);
	int size();
};
