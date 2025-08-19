
#ifndef STUDENT_H
#define STUDENT_H

#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

class Student
{
    string name;
    int rollNo;
    static int totalStudents;
public:
    static vector< pair<string,int> > names;
    Student();

    static void getTotalStudents();
    static void displayAllStudents();

    friend ostream& operator<<(ostream& out, Student& sd);
    friend istream& operator>>(istream& in, Student& sd);
};
int Student::totalStudents = 0;


#endif //STUDENT_H
