
#include <iostream>
#include <Windows.h>
#include <string>

class Figure {
public:
    virtual double GetArea() const  = 0;
};

class MyRectangle : public Figure {
private:
    double width;
    double height;
public:
    MyRectangle() : width(0), height(0) {};
    MyRectangle(double width, double height) : width(width), height(height) {};
    double GetArea() const override {
        double result = width * height;
        return result;
    }
};

class Circle : public Figure {
private:
    double radius;
public:
    Circle() : radius(0) {};
    Circle(double radius) : radius(radius) {};
    double GetArea() const override {
        double result = 3.14 * (radius * radius);
        return result;
    }
};

class Triangle : public Figure {
private:
    double base;
    double height;
public:
    Triangle() : base(0), height(0) {};
    Triangle(double base, double height) : base(base), height(height) {};
    double GetArea() const override {
        double result = 0.5 * base * height;
        return result;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        int choice = 0;
        while (choice <= 0 || choice > 4) {
            std::cout << "Выберите тип фигуры: \n1. Прямоугольник\n2. Окружность\n3. Треугольник\n4. Выход\n>";
            std::cin >> choice;
        }
        std::cin.ignore();
        switch (choice) {
        case 1: {
            double width;
            double height;
            std::cout << "Введите ширину прямоугольника: ";
            std::cin >> width;
            std::cout << "Введите высоту прямоугольника: ";
            std::cin >> height;
            MyRectangle figure = MyRectangle(width, height);
            std::cout << "Площадь прямоугольника: " << figure.GetArea() << '\n';
            break;
        }
        case 2: {
            double radius;
            std::cout << "Введите радиус окружности: ";
            std::cin >> radius;
            Circle figure = Circle(radius);
            std::cout << "Площадь окружности: " << figure.GetArea() << '\n';
            break;
        }
        case 3: {
            double base;
            double height;
            std::cout << "Введите основание треугольника: ";
            std::cin >> base;
            std::cout << "Введите высоту треугольника: ";
            std::cin >> height;
            Triangle figure = Triangle(base, height);
            std::cout << "Площадь треугольника: " << figure.GetArea() << '\n';
            break;
        }
        }
        if (choice == 4) {
            std::cout << "До свидания!";
            break;
        }
    }
}

