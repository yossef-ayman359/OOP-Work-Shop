
#include "Circle.h"
#include "cmath"

double Circle::area()
{
    return M_PI * radius * radius;
}

double Circle::perimeter()
{
    return 2 * M_PI * radius;
}

istream& operator>>(istream& in, Circle& c)
{
    cout << "\tRadius.\n";
    in >> c.radius;
    return in;
}

ostream& operator<<(ostream& out, Circle c)
{
    out << "Radius: " << c.radius << "\nArea = " << c.area() << "\nPerimeter = " << c.perimeter() << '\n';
    return out;
}

