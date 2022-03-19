#include "LinkedList.h"

template<class _El>
bool LinkedList<_El>::push_back(_El& el)
{
    auto node = new Node<_El>(el);
    if (cur_size == 0)
        head = tail = node;

    else
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    cur_size++;
    return true;
}

template<class _El>
_El& LinkedList<_El>::pop_back()
{
    if (!head)
        throw ValueError("the list is empty");

    auto el = tail->el;

    auto node = head;
    if (!node->next)
    {
        tail = head = nullptr;
        cur_size--;
        return el;
    }

    for (; node->next != tail; node = node->next);
    tail = node;
    tail->next = nullptr;
    cur_size--;

    return el;
}

template<class _El>
Node<_El>& LinkedList<_El>::begin()
{
    if (!head)
        throw ValueError("the list is empty");

    return *head;
}

template<class _El>
Node<_El>& LinkedList<_El>::end()
{
    if (!tail)
        throw ValueError("the list is empty");

    return *tail;
}

template<class _El>
int LinkedList<_El>::size()
{
    return cur_size;
}

template<class _El>
std::ostream& operator<<(std::ostream& os, const LinkedList<_El>& list)
{
    os << "\nThis list has:\n";
    for (auto i = list.head; i != nullptr; i = i->next)
        os << i->el << '\n';
    os << std::endl;
    return os;
}
