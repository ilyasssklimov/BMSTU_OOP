#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <time.h>
#include "iterator.h"
#include "exception.hpp"


template <typename T>
ListIterator<T>::ListIterator()
{
    pointer.lock() = nullptr;
}


template <typename T>
ListIterator<T>::ListIterator(const ListIterator<T> &iterator)
{
    pointer = iterator.pointer.lock();
}


template <typename T>
ListIterator<T>::ListIterator(const shared_ptr<ListNode<T>> &node)
{
    pointer = node;
}


template <typename T>
void ListIterator<T>::next(void)
{
    is_shared(__LINE__);
    pointer = pointer.lock()->get_next();
}


template <typename T>
ListIterator<T> &ListIterator<T>::operator += (const int size)
{
    if (size < 0)
    {
        time_t time_now = time(NULL);
        throw SizeError(__FILE__, __LINE__, ctime(&time_now));
    }

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
    ListIterator<T> tmp(*this);
    next();
    return tmp;
}


template <typename T>
ListIterator<T> ListIterator<T>::operator + (const int size) const
{
    ListIterator<T> tmp(*this);
    tmp += size;
    return tmp;
}


template <typename T>
ListIterator<T> ListIterator<T>::operator = (const ListIterator<T> &iterator)
{
    // is_shared(__LINE__);
    pointer = iterator.pointer.lock();
    return *this;
}


template <typename T>
bool ListIterator<T>::operator != (const ListIterator<T> &iterator) const
{
    // is_shared(__LINE__);
    return pointer.lock() != iterator.pointer.lock();
}


template <typename T>
bool ListIterator<T>::operator == (const ListIterator<T> &iterator) const
{
    // is_shared(__LINE__);
    return pointer.lock() == iterator.pointer.lock();
}


template <typename T>
ListIterator<T>::operator bool() const
{
    // is_shared(__LINE__);
    return pointer.lock() != nullptr;
}


template <typename T>
ListNode<T> *ListIterator<T>::operator -> ()
{
    is_shared(__LINE__);
    return pointer.lock().get();
}


template <typename T>
const ListNode<T> *ListIterator<T>::operator -> () const
{
    is_shared(__LINE__);
    return pointer.lock().get();
}


template <typename T>
ListNode<T> &ListIterator<T>::operator * ()
{
    is_shared(__LINE__);
    return *pointer.lock();
}


template <typename T>
const ListNode<T> &ListIterator<T>::operator * () const
{
    is_shared(__LINE__);
    return *pointer.lock();
}


template <typename T>
void ListIterator<T>::is_shared(int line) const
{
    if (pointer.expired())
    {
        time_t time_now = time(NULL);
        throw SharedPtrError(__FILE__, line, ctime(&time_now));
    }
}



#endif
