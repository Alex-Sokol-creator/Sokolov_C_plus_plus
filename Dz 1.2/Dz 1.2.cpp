//Dz 1 moved

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "First Task" << '\n';
    std::cout << "Введите время в секундах для их конвертации: ";
    long seconds_time;
    std::cin >> seconds_time;
    double minuts_time = seconds_time / 60.0;
    std::cout << '\n' << "Время в минутах: " << minuts_time;

}

