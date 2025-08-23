
#ifndef STUDENT_H
#define STUDENT_H

#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

template <class T>
class Student;

// template <class T>
// extern vector< Student<T> > students;

template <class T>
void printTopStudent();

template <class T>
void printAll();

template <class T>
class StudentUtils
{
public:
    static vector< Student<T> > students;

    static void printTopStudent();
    static void printAll();

    friend class Student<T>;
};

template <class T>
istream& operator>>(istream& in, Student<T>& sdt);

template <class T>
ostream& operator<<(ostream& out, Student<T>& sdt);

template <class T>
bool isBetter(const Student<T>& s1, const Student<T>& s2);

template <class T>
class Student
{
  string name; T id;
  static int cnt;
public:
  T grade;
  Student();
  Student(string name, T id, T grade=0);

  static void Count_stud();

  friend bool isBetter<T>(const Student<T>& s1, const Student<T>& s2);

  friend class StudentUtils <T>;

  friend istream& operator>><T>(istream& in, Student<T>& sdt);
  friend ostream& operator<<<T>(ostream& out, Student<T>& sdt);
    ~Student();
};

template <class T>
int Student<T>::cnt = 0;

#endif //STUDENT_H
