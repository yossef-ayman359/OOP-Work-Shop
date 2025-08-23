#include <bits/stdc++.h>
#include "Student.cpp"

#define endl '\n'
#define FAST ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define us unsigned short
#define ll long long
#define for0(n) for(int i=0; i<n; ++i)
#define for1(n) for(int i=1; i<n; ++i)

using namespace std;

int main()
{
    Student<int> st, st1, st2 ,st3("kdm", 61656, 100);
    cin >> st >> st1 >> st2;
    cout << st;
    cout << (isBetter(st, st1) ? "True" : "False") << endl;
    StudentUtils<int>::printAll();
    StudentUtils<int>::printTopStudent();
    Student<int>::Count_stud();
}