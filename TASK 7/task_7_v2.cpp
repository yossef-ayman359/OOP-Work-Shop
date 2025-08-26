#include "bits/stdc++.h"

using namespace std;

int main()
{
  vector<int> v = {1,2,3,4,5};
  cout << "\tFor each:\n";
  // for_each(v.begin(), v.end(), [] (int& a) { a *= 2;});
  for_each(v.begin(), v.end(), [] (auto a) { cout << a*2 << ' ';});

  cout << "\n\tFind if:\n";
  cout << "First even number = " << *find_if(v.begin(), v.end(), [] (auto a) {return a%2 == 0;});

  cout << "\n\tCount if:\n";
  cout << "Even numbers = " << count_if(v.begin(), v.end(), [] (auto a) {return a%2 == 0;}) << endl;
  cout << "Odd numbers = " << count_if(v.begin(), v.end(), [] (auto a) {return a%2 == 1;});

}