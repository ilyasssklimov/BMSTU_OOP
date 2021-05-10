#ifndef NODE_HPP
#define NODE_HPP


#include <iostream>
#include "node.h"


template <typename T>
ListNode<T>::ListNode()
{
    next = nullptr;
}


template <typename T>
ListNode<T>::ListNode(const T &new_data)
{
    data = new_data;
    next = nullptr;
}


template <typename T>
ListNode<T>::ListNode(shared_ptr<ListNode<T>> &node)
{
    data = node->data;
    next = node->next;
}



template <typename T>
void ListNode<T>::put_null()
{
    next = nullptr;
}


template <typename T>
void ListNode<T>::put_cur(const T &cur_data)
{
    data = cur_data;
}


template <typename T>
void ListNode<T>::put_next(const shared_ptr<ListNode<T>> &node)
{
    next = node;
}


template <typename T>
void ListNode<T>::put_next(const ListNode<T> &node)
{
    shared_ptr<ListNode<T>> ptr_to_node(node);
    next = ptr_to_node;
}


template <typename T>
T& ListNode<T>::get_data()
{
   return data;
}


template <typename T>
const T& ListNode<T>::get_data() const
{
   return data;
}


template <typename T>
shared_ptr<ListNode<T>> ListNode<T>::get_next(void)
{
    return next;
}


template <typename T>
bool ListNode<T>::operator == (const shared_ptr<ListNode<T>> &node) const
{
    return this == node;
}


template <typename T>
bool ListNode<T>::operator != (const shared_ptr<ListNode<T>> &node) const
{
    return this != node;
}


#endif
