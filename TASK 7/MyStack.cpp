
#include "MyStack.h"

template<class T>
MyStack<T>::MyStack(){}

template<class T>
void MyStack<T>::push(T n )
{
  d.push_back(n);
}

template<class T>
void MyStack<T>::pop()
{
  d.pop_back();
}

template<class T>
void MyStack<T>::clear()
{
  d.clear();
}

template<class T>
int MyStack<T>::size()
{
  return (int) d.size();
}

template<class T>
bool MyStack<T>::empty()
{
  return d.empty();
}

template<class T>
T MyStack<T>::top()
{
  return d.back();
}