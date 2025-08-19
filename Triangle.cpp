
#include "Triangle.h"

Triangle::Triangle()
{
    side1 = side2 = side3 = 0;
}

double Triangle::perimeter()
{
    return side1 + side2 + side3;
}
double Triangle::area()
{
    double p;
    p = perimeter()/2.0;
    p = p * (p-side1) * (p-side2) * (p-side3);
    return sqrt(p);
}

istream& operator>>(istream& in, Triangle& t)
{
    cout << "\tSide1 & Side2 & Side3.\n";
    in >> t.side1 >> t.side2 >> t.side3;
    return in;
}

ostream& operator<<(ostream& out, Triangle t)
{
    out << "Side1 = " << t.side1 << '\n'
        << "Side1 = " << t.side1 << '\n'
        << "Side1 = " << t.side1 << '\n'
        << "Area by Heron’s formula = " << t.area() << '\n';
    return out;
}

