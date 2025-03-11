#pragma once

#include <iostream>

class Trapeze
{
private:
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double x4, y4;

public:

    // Конструктори
    Trapeze();
    Trapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    Trapeze(const Trapeze& other);

    // Делегування конструктора
    Trapeze(double x1, double y1);
    

    ~Trapeze();

    // Сетери
    void setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    void setCoordinates(const double coords[8]);

    // Гетери
    double getX1() const;
    double getY1() const;
    double getX2() const;
    double getY2() const;
    double getX3() const;
    double getY3() const;
    double getX4() const;
    double getY4() const;

    // Методи обчислення
    double getPerimeter() const;
    double getArea() const;

    // Перевантаження оператора множення
    Trapeze operator*(const Trapeze& other) const;

    // Перевантаження оператора вирахування
    Trapeze operator-(double subtract) const;

    // Перевантаження оператора виведення
    friend std::ostream& operator<<(std::ostream& os, const Trapeze& trapeze);

    // Оператор +=
    Trapeze& operator+=(const Trapeze& other);
};