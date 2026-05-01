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
    std::cout << '\n' << "В минутах это: " << minuts_time << "минут(ы)";
    double hours_time = seconds_time / 3600.0;
    std::cout << '\n' << "В часах это: " << hours_time << "часа(ов)";
    std::cout << '\n' << "В секундах это: " << seconds_time << "секунд(ы)";

    std::cout << '\n' << "Second Task" << '\n';
    std::cout << "Введите денежную дробь для ее конвертации в гривны и копейки: ";
    float money;
    std::cin >> money;
    int money_general = money;
    std::cout << '\n' << money_general;
}

