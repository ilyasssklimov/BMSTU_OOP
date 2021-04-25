#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator.h"


template <typename T>
ListIterator<T>::ListIterator()
{
    pointer.lock() = nullptr;
}


template <typename T>
ListIterator<T>::ListIterator(const ListIterator<T> &iterator)
{
    pointer.lock() = iterator.pointer.lock();
}


template <typename T>
ListIterator<T>::ListIterator(const shared_ptr<ListNode<T>> &node)
{
    pointer = node;
}


template <typename T>
void ListIterator<T>::next(void)
{
    pointer = pointer.lock()->get_next();
}


template <typename T>
ListIterator<T> &ListIterator<T>::operator += (const int &size)
{
    for (int i = 0; i < size; i++)
        next();

    return *this;
}


template <typename T>
ListIterator<T> &ListIterator<T>::operator ++ ()
{
    next();
    return *this;
}


template <typename T>
ListIterator<T> ListIterator<T>::operator ++ (int)
{
    ListIterator<T> temp(*this);
    ++temp;
    return temp;
}


template <typename T>
ListIterator<T> ListIterator<T>::operator + (const int &size)
{
    ListIterator<T> temp(*this);
    temp += size;
    return temp;
}


template <typename T>
ListIterator<T> ListIterator<T>::operator = (const ListIterator<T> &iterator)
{
    pointer = iterator.pointer.lock();
    return *this;
}


template <typename T>
bool ListIterator<T>::operator != (const ListIterator<T> &iterator) const
{
    return pointer.lock() != iterator.pointer.lock();
}


template <typename T>
bool ListIterator<T>::operator == (const ListIterator<T> &iterator) const
{
    return pointer.lock() == iterator.pointer.lock();
}


template <typename T>
ListIterator<T>::operator bool() const
{
    return pointer.lock() != nullptr;
}


template <typename T>
T *ListIterator<T>::operator -> ()
{
    return pointer.lock();
}
#endif
