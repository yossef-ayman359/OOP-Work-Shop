
#include "Student.h"

template<class T>
vector< Student<T> > StudentUtils<T>::students;

template<class T>
Student<T>::Student(string name, T id, T grade) : name(name), id(id), grade(grade) {cnt++; StudentUtils<T>::students.push_back(*this);}

template<class T>
Student<T>::Student() : name("No name"), id(0), grade(0) {}

template<class T>
Student<T>::~Student() { cnt--; }

template<class T>
istream& operator>>(istream& in, Student<T>& sdt)
{
  cout << "Name & Id & Grade:\n";
  in >> sdt.name >> sdt.id >> sdt.grade;
  StudentUtils<T>::students.push_back(sdt);
  Student<T>::cnt++;
  return in;
}

template<class T>
ostream& operator<<(ostream& out, Student<T>& s)
{
  out << "\tName: " << s.name << "\n\tId: " << s.id << "\n\tGrade: " << s.grade << endl;
  return out;
}

template<class T>
bool isBetter(const Student<T>& s1, const Student<T>& s2)
{
  return s1.grade > s2.grade;
}

string s = "---------------------------------------\n";
template<class T>
void StudentUtils<T>::printTopStudent()
{
  int max(0);
  Student<T> temp_s;
  for (auto it : students)
  {
    if (it.grade > max)
      temp_s = it, max = it.grade;
  }
  cout << "The best student:\n";
  cout << temp_s << s;
}

template<class T>
void StudentUtils<T>::printAll()
{
  cout << s << "Print mode\n" << s;
  for(auto& it : students)
    cout << it << s;
}

template<class T>
void Student<T>::Count_stud()
{
  cout << "Number of student: " << (cnt < 0 ? -cnt : cnt) << endl;
}
