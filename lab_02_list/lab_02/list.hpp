#ifndef LIST_HPP
#define LIST_HPP


#include <iostream>
#include "list.h"
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> List<T>::get_head()
{
    return this->head;
}


template <typename T>
shared_ptr<ListNode<T>> List<T>::get_tail()
{
    return tail;
}


template <typename T>
List<T>::List(void)
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}


template <typename T>
List<T>::List(List<T> &list)
{
    size = 0;
    head = nullptr;
    tail = nullptr;

    for (auto node: list)
    {

    }
}

template <typename T>
List<T>::List(List<T> &&list)
{
    this->size = list.size;
    this->head = list.head;
    this->tail = list.tail;
}




#endif
