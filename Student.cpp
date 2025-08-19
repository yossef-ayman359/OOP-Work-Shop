
#include "Student.h"

vector< pair<string,int> > Student::names;


Student::Student()
{
    name = "NO name";
    rollNo = 0;
    totalStudents++;
}

void Student::getTotalStudents()
{
    cout << "Number of student is: " << totalStudents << '\n';
    cout << "Number of unregistered students: " << totalStudents-names.size() << endl;
    cout << "____________________________________\n";
}

void Student::displayAllStudents()
{
    cout << "\n\tShow all registered students:\n\n";
    for (auto it : names)
        {
        cout << "Student name: " << it.first << "\n Student roll no: " << it.second << '\n';
        cout << "____________________________________\n";
    }
}

ostream& operator<<(ostream& out, Student& sd)
{
    out << "Student name: " << sd.name << "\n Student roll no: " << sd.rollNo << endl;
    return out;
}
istream& operator>>(istream& in, Student& sd)
{
    cout << "Name & Roll no.\n";
    in >> sd.name >> sd.rollNo;
    Student::names.push_back({sd.name, sd.rollNo});
    return in;
}

// int Student::totalStudents = 0;
