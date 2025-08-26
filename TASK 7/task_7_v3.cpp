#include "MyStack.cpp"

int main()
{
  MyStack<int> s;

  s.push(5);
  s.push(3);
  s.push(7);

  cout << s.size() << endl;

  while(!s.empty())
  {
    cout << s.top() << ' ';
    s.pop();
  }
  cout << endl;

  s.clear();
  cout << s.size() << endl;


  return 0;
}