
#include "Rectangle.h"

double Rectangle::area()
{
    return length * width;
}

double Rectangle::perimeter()
{
    return 2 * (length + width);
}

istream& operator>>(istream& in, Rectangle& r)
{
    cout << "\tLength & Width.\n";
    in >> r.length >> r.width;
    return in;
}

ostream& operator<<(ostream& out, Rectangle r)
{
    out << "Length: " << r.length << "\tWidth: " << r.width << "\nArea = " << r.area() << "\nPerimeter = " << r.perimeter() << '\n';
    return out;
}