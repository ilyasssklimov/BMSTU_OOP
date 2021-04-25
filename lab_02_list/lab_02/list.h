#ifndef LIST_H
#define LIST_H


#include <iostream>
#include "node.h"
#include "base_list.hpp"
using namespace std;


template <typename T>
class List: public BaseList
{
private:
    size_t size;
    shared_ptr<ListNode<T>> head;
    shared_ptr<ListNode<T>> tail;

protected:
    shared_ptr<ListNode<T>> get_head();
    shared_ptr<ListNode<T>> get_tail();

public:
    List();
    List(List<T> &list);
    List(List<T> &&list);

    ~List() = default;
};


#endif
