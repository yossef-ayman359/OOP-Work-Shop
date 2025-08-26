
#ifndef MYSTACK_H
#define MYSTACK_H

#include "bits/stdc++.h"
using namespace std;

template<class T>
class MyStack
{
    deque<T> d;
public:
    MyStack();
    void push(T n);
    void pop();
    void clear();
    int size();
    bool empty();
    T top();
};



#endif //MYSTACK_H
