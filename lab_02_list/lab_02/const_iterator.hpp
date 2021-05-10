#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include <time.h>
#include "const_iterator.h"
#include "exception.hpp"


template <typename T>
ConstListIterator<T>::ConstListIterator()
{
    pointer = nullptr;
}


template <typename T>
ConstListIterator<T>::ConstListIterator(const ConstListIterator<T> &iterator)
{
    pointer = iterator.pointer.lock();
}


template <typename T>
ConstListIterator<T>::ConstListIterator(const shared_ptr<ListNode<T>> &node)
{
    pointer = node;
}


template <typename T>
void ConstListIterator<T>::next(void)
{
    is_shared(__LINE__);
    pointer = pointer.lock()->get_next();
}


template <typename T>
ConstListIterator<T> &ConstListIterator<T>::operator += (const int size)
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
ConstListIterator<T> &ConstListIterator<T>::operator ++ ()
{
    next();
    return *this;
}


template <typename T>
ConstListIterator<T> ConstListIterator<T>::operator ++ (int)
{
    ConstListIterator<T> tmp(*this);
    next();
    return tmp;
}


template <typename T>
ConstListIterator<T> ConstListIterator<T>::operator + (const int size) const
{
    ConstListIterator<T> temp(*this);
    temp += size;
    return temp;
}


template <typename T>
ConstListIterator<T> ConstListIterator<T>::operator = (const ConstListIterator<T> &iterator)
{
    // is_shared(__LINE__);
    pointer = iterator.pointer.lock();
    return *this;
}


template <typename T>
bool ConstListIterator<T>::operator != (const ConstListIterator<T> &iterator) const
{
    // is_shared(__LINE__);
    return pointer.lock() != iterator.pointer.lock();
}


template <typename T>
bool ConstListIterator<T>::operator == (const ConstListIterator<T> &iterator) const
{
    // is_shared(__LINE__);
    return pointer.lock() == iterator.pointer.lock();
}


template <typename T>
ConstListIterator<T>::operator bool() const
{
    // is_shared(__LINE__);
    return pointer.lock() != nullptr;
}


template <typename T>
const ListNode<T> *ConstListIterator<T>::operator -> () const
{
    is_shared(__LINE__);
    return pointer.lock().get();
}


template <typename T>
const ListNode<T> &ConstListIterator<T>::operator * () const
{
    is_shared(__LINE__);
    return *pointer.lock().get();
}


template <typename T>
void ConstListIterator<T>::is_shared(int line) const
{
    if (pointer.expired())
    {
        time_t time_now = time(NULL);
        throw SharedPtrError(__FILE__, line, ctime(&time_now));
    }
}

#endif
