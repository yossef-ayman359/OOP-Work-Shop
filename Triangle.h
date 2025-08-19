//
// Created by pc on 19/08/2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
    double side1,side2,side3;
public:
    Triangle();

    double area() override;
    double perimeter() override;

    friend istream& operator>>(istream& in, Triangle& t);
    friend ostream& operator<<(ostream& out, Triangle t);
};



#endif //TRIANGLE_H
