
#include <iostream>
#include <Windows.h>

class Vehicle {
protected:
    std::string brand;
    int speed;
public:
    Vehicle() : Vehicle("default",0) {}

    Vehicle(std::string brand, int speed) : brand(brand), speed(speed) {
        std::cout << "[LOG]: Vehicle ctor." << '\n';
    }

    ~Vehicle() {
        std::cout << "[LOG]: Vehicle dtor\n";
    }

    void ShowInfo() const {
        std::cout << "Brand: " << brand << "\nSpeed " << speed << "km/h.\n";
    }
};

class Car : public virtual Vehicle {
private:
    int passengerCapacity;
public:
    Car(std::string brand, int speed, int passengerCapacity):
        Vehicle(brand,speed), passengerCapacity(passengerCapacity) { 
        std::cout << "[LOG]: Car ctor." << '\n';
    }

    ~Car() {
        std::cout << "[LOG]: Car dtor\n";
    }

    void ShowInfo() const {
        Vehicle::ShowInfo();
        std::cout <<"Passangers: " << passengerCapacity << '\n';
    }
};

class Airplane : public virtual Vehicle {
private:
    int flyHeight;
public:
    Airplane(std::string brand, int speed, int flyHeight) :
        Vehicle(brand, speed), flyHeight(flyHeight) {
        std::cout << "[LOG]: Airplane ctor" << '\n';
    }

    ~Airplane() {
        std::cout << "[LOG]: Airplane dtor\n";
    }

    void ShowInfo() const {
        Vehicle::ShowInfo();
        std::cout << "Fly height: " << flyHeight << '\n';
    }
};

class FlyingCar : public Car, public Airplane {
private:
    double cost;
public:
    FlyingCar(std::string brand, int speed, int passengerCapacity, int flyHeight, double cost) :
        Car(brand, speed, passengerCapacity), Airplane(brand, speed, flyHeight), cost(cost) {
        std::cout << "[LOG]: FlyingCar ctor" << '\n';
    }

    ~FlyingCar() {
        std::cout << "[LOG]: FlyingCar dtor\n";
    }

    void ShowInfo() const {
        //Car::ShowInfo();
        //Airplane::ShowInfo();
        std::cout << "Brand: " << Vehicle::brand << '\n';
        std::cout << "Cost: " << cost << "$\n";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Car car("Volvo", 280, 5);
    car.ShowInfo();

    FlyingCar Tesla("Tesla", 400, 5, 100, 1000000.99);
    Tesla.ShowInfo();
}

