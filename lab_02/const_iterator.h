#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H


#include "node.h"
using namespace std;


template <typename T>
class ConstListIterator
{

public:
    ConstListIterator();
    ConstListIterator(const ConstListIterator<T> &iterator);
    ConstListIterator(const shared_ptr<ListNode<T>> &node);

    virtual void next();

    ConstListIterator<T> &operator += (const int size);
    ConstListIterator<T> &operator ++ ();
    ConstListIterator<T> operator ++ (int);
    ConstListIterator<T> operator + (const int size) const;
    ConstListIterator<T> operator = (const ConstListIterator<T> &iterator);

    bool operator != (const ConstListIterator<T> &iterator) const;
    bool operator == (const ConstListIterator<T> &iterator) const;

    operator bool() const;

    const ListNode<T> *operator -> () const;
    const ListNode<T> &operator * () const;

protected:
    void is_shared(int line) const;

private:
    weak_ptr<ListNode<T>> pointer;
};


#endif
