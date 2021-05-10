#ifndef ITERATOR_H
#define ITERATOR_H


#include "node.h"
using namespace std;


template <typename T>
class ListIterator
{
public:
    ListIterator();
    ListIterator(const ListIterator<T> &iterator);
    ListIterator(const shared_ptr<ListNode<T>> &node);

    virtual void next();

    ListIterator<T> &operator += (const int size);
    ListIterator<T> &operator ++ ();
    ListIterator<T> operator ++ (int);
    ListIterator<T> operator + (const int size) const;
    ListIterator<T> operator = (const ListIterator<T> &iterator);

    bool operator != (const ListIterator<T> &iterator) const;
    bool operator == (const ListIterator<T> &iterator) const;

    operator bool() const;

    ListNode<T> *operator -> ();
    const ListNode<T> *operator -> () const;
    ListNode<T> &operator * ();
    const ListNode<T> &operator * () const;

protected:
    void is_shared(int line) const;

private:
    weak_ptr<ListNode<T>> pointer;

};


#endif
