#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>
using namespace std;


template <typename T>
class ListNode
{
private:
    T data;
    shared_ptr<ListNode<T>> next;

public:
    ListNode();
    ListNode(const T &new_data);
    ListNode(shared_ptr<ListNode<T>> &node);

    void put_null();
    void put_cur(const T &cur_data);
    void put_next(const shared_ptr<ListNode<T>> &node);
    void put_next(const ListNode<T> &node);

    T &get_data();
    shared_ptr<ListNode<T>> get_next();

    bool operator == (const shared_ptr<ListNode<T>> &node) const;
    bool operator != (const shared_ptr<ListNode<T>> &node) const;

    ~ListNode() = default;
};


#endif
