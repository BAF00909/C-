#pragma once
#define PI 3.14;
using namespace std;

class Figure {
public:
    virtual float area() = 0;
};

class Parallelogram : public Figure {
protected:
    float S = 0.0;
    float side; // сторона параллелограма 
    float height; // высота продеденая к стороне параллелограма
public:
    Parallelogram(float s, float h) : side(s), height(h) {};
    float area() override {
        S = side * height;
        cout << "Площадь параллелограма = " << S << endl;
        return S;
    }
};

class Circle : public Figure {
private:
    double S = 0.0;
    float radius;
public:
    Circle(float r) : radius(r) {};
    float area() override {
        S = (radius * radius) * PI;
        cout << "Площадь круга = " << S << endl;
        return S;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(float s, float h) : Parallelogram(s, h) {};
    float area() override {
        S = 0.5 * side * height;
        cout << "Площадь треугольника = " << S << endl;
        return S;
    }
};

class Square : public Parallelogram {
public:
    Square(float s, float h) : Parallelogram(s, h) {};
    float area() override {
        S = side * height;
        cout << "Площадь квадрата = " << S << endl;
        return S;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(float s, float h) : Parallelogram(s, h) {};
    float area() override {
        S = side * height;
        cout << "Площадь ромба = " << S << endl;
        return S;
    }
};