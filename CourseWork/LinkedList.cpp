#include "LinkedList.h"

template<class _El>
bool LinkedList<_El>::push_back(_El& el)
{
    auto node = new Node<_El>(el);
    //node->el = el;
    if (cur_size == 0)
        head = tail = node;

    else
    {
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
        throw 1;

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
Node<_El>& LinkedList<_El>::front()
{
    return *head;
}

//bool LinkedList::push_front(Dekanat el)
//{
//    auto node = new Node;
//    node->el = el;
//
//    if (!head)
//        head = tail = node;
//
//    else
//    {
//        node->next = head;
//        head = node;
//    }
//    return true;
//}

//Dekanat LinkedList::pop_front()
//{
//    if (!head)
//        throw EmptyListException();
//
//    auto el = head->el;
//    if (!head->next)
//        head = tail = nullptr;
//    else
//        head = head->next;
//    return el;
//}
//
//Dekanat LinkedList::get(int index)
//{
//    auto node = head;
//    int count = 0;
//    for (; count != index; node = node->next, count++);
//
//    return node->el;
//}

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
