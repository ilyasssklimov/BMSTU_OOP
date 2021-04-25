#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>
#include "node.h"
using namespace std;


template <typename T>
class ListIterator: iterator<input_iterator_tag, T>
{
private:
    weak_ptr<ListNode<T>> pointer;

public:
    ListIterator();
    ListIterator(const ListIterator<T> &iterator);
    ListIterator(const shared_ptr<ListNode<T>> &node);

    virtual void next();

    ListIterator<T> &operator += (const int &size);
    ListIterator<T> &operator ++ ();
    ListIterator<T> operator ++ (int);
    ListIterator<T> operator + (const int &size);
    ListIterator<T> operator = (const ListIterator<T> &iterator);

    bool operator != (const ListIterator<T> &iterator) const;
    bool operator == (const ListIterator<T> &iterator) const;

    operator bool() const;

    T *operator -> ();

    /*
    list_node<T> *operator ->();
     const list_node<T> *operator ->() const;

     const list_node<T> &operator *() const;
     list_node<T> &operator *();

   */
};
#endif
