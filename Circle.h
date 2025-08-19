
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
protected:
    double radius;
public:
    double area() override;
    double perimeter() override;

    friend istream& operator>>(istream& in, Circle& r);
    friend ostream& operator<<(ostream& out, Circle r);
};

#endif //CIRCLE_H
