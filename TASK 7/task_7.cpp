#include "bits/stdc++.h"

using namespace std;

template<typename T>
void filter(vector<T>& v, vector<T> (*func) (vector<T>))
{
    v = func(v);
    // return v; if filter return type vector<T>
}


vector<int> even(vector<int> v)
{
    int x = v.size();
    vector<int> temp;
    for (int i=0; i < x; ++i)
    {
        if (v[i] % 2 == 0)
            temp.push_back(v[i]);
    }
    return temp;
}

vector<double> gpa(vector<double> v)
{
    int x = v.size();
    vector<double> temp;
    for (int i=0; i < x; ++i)
    {
        if (v[i] >= 3.0)
            temp.push_back(v[i]);
    }
    return temp;

}

vector<string> angry_character(vector<string> v)
{
    int x = v.size();
    vector<string> temp;
    for (int i=0; i < x; ++i)
    {
        if (v[i].size() <= 18)
            temp.push_back(v[i]);
    }
    return temp;
}

int main()
{

    vector<int> v = {1,2,3,4,5,6};
    filter(v, even);

     vector<double> v1 = {3.0, 3.2, 1.5, 2.9, 4.0};
     filter(v1, gpa);

     vector<string> v2 = {"asdfghjklqwertyuio", "yossef", "asdfghjklqwertyuiof"};
     filter(v2, angry_character);


     for (auto it : v)
         cout << it << ' ';  // 2 4 6
cout << endl;


    for (auto it : v1)
        cout << it << ' ';  // 3 3.2 4
cout << endl;


    for (auto it : v2)
        cout << it << ' ';  // index (0, 1) only
}