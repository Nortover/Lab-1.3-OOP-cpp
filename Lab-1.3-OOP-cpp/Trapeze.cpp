#include "Trapeze.h"
#include <cmath> 
#include <iostream>

// Конструктор за замовчуванням 
Trapeze::Trapeze()
    : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0), x4(0), y4(0)
{
}

// Конструктор за параметрами
Trapeze::Trapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4)
{
}

// Конструктор копії
Trapeze::Trapeze(const Trapeze& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4)
{
}

// Делегування конструктора
Trapeze::Trapeze(double x1, double y1) : Trapeze(x1, y1, 0, 0, 0, 0, 0, 0)
{
}

Trapeze::~Trapeze() {

}

// Сетери
void Trapeze::setCoordinates(double X1, double Y1, double X2, double Y2, double X3, double Y3, double X4, double Y4)
{
    x1 = X1;
    y1 = Y1;
    x2 = X2;
    y2 = Y2;
    x3 = X3;
    y3 = Y3;
    x4 = X4;
    y4 = Y4;

}

// Перевантаження: встановлення координат через масив з 8 елементів
void Trapeze::setCoordinates(const double coords[8]) {
    x1 = coords[0]; y1 = coords[1];
    x2 = coords[2]; y2 = coords[3];
    x3 = coords[4]; y3 = coords[5];
    x4 = coords[6]; y4 = coords[7];
}

// Гетери
double Trapeze::getX1() const { return x1; }
double Trapeze::getY1() const { return y1; }
double Trapeze::getX2() const { return x2; }
double Trapeze::getY2() const { return y2; }
double Trapeze::getX3() const { return x3; }
double Trapeze::getY3() const { return y3; }
double Trapeze::getX4() const { return x4; }
double Trapeze::getY4() const { return y4; }


double Trapeze::getPerimeter() const
{
   
    double sideA = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double sideB = std::sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double sideC = std::sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double sideD = std::sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));

    return sideA + sideB + sideC + sideD;

}


double Trapeze::getArea() const
{
    double sideA = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double sideB = std::sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double sideC = std::sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double sideD = std::sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));

    double p = (sideA + sideB + sideC + sideD) / 2.0;
    double part = (sideA + sideC) / (abs(sideA + sideC));
    return std::abs((sideA + sideC) / (sideA + sideC) * sqrt(p * (p - sideA) * (p - sideB) * (p - sideC) * (p - sideD)));

}

void Trapeze::scale(double factor)
{
    x1 *= factor;
    y1 *= factor;
    x2 *= factor;
    y2 *= factor;
    x3 *= factor;
    y3 *= factor;
    x4 *= factor;
    y4 *= factor;

}

Trapeze Trapeze::scale(double factor, Trapeze other)
{
    other.x1 *= factor;
    other.y1 *= factor;
    other.x2 *= factor;
    other.y2 *= factor;
    other.x3 *= factor;
    other.y3 *= factor;
    other.x4 *= factor;
    other.y4 *= factor;
    return other;
}

void Trapeze::scale(Trapeze& other, double factor)
{
    other.x1 *= factor;
    other.y1 *= factor;
    other.x2 *= factor;
    other.y2 *= factor;
    other.x3 *= factor;
    other.y3 *= factor;
}


// Перевантаження оператора * для множення двох трапецій
Trapeze Trapeze::operator*(const Trapeze& other) const {
    return Trapeze(x1 * other.x1, y1 * other.y1,
        x2 * other.x2, y2 * other.y2,
        x3 * other.x3, y3 * other.y3,
        x4 * other.x4, y4 * other.y4);
    }


// Перевантаження оператора вирахування
Trapeze Trapeze::operator-(double subtract) const {
    return Trapeze(
        x1 - subtract, y1 - subtract,
        x2 - subtract, y2 - subtract,
        x3 - subtract, y3 - subtract,
        x4 - subtract, y4 - subtract
    );
}

// Перевантаження оператора присвоювання
Trapeze& Trapeze::operator+=(const Trapeze& other) {
    x1 += other.x1;
    y1 += other.y1;
    x2 += other.x2;
    y2 += other.y2;
    x3 += other.x3;
    y3 += other.y3;
    x4 += other.x4;
    y4 += other.y4;
    return *this;
}
    // Перевантаження оператора виведення
    std::ostream& operator<<(std::ostream & os, const Trapeze & trapeze) {
        os << "Trapeze(" << trapeze.x1 << ", " << trapeze.y1 << ", " << trapeze.x2 << ", " << trapeze.y2 << ", " << trapeze.x3 << ", " << trapeze.y3 << ", " << trapeze.x4 << ", " << trapeze.y4 << ")";
        return os;
}
