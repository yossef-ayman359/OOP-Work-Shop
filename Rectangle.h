
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
protected:
    double length, width;
public:
    double area() override;
    double perimeter() override;

    friend istream& operator>>(istream& in, Rectangle& r);
    friend ostream& operator<<(ostream& out, Rectangle r);
};

#endif //RECTANGLE_H
