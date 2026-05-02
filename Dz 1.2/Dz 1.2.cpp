//Dz 1 moved

#include <iostream>
#include <Windows.h>

int main()
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //{
    //    std::cout << "First Task" << '\n';
    //    std::cout << "Введите время в секундах для их конвертации: ";
    //    long seconds_time;
    //    std::cin >> seconds_time;
    //    double minuts_time = seconds_time / 60.0;
    //    std::cout << '\n' << "В минутах это: " << minuts_time << "минут(ы)";
    //    double hours_time = seconds_time / 3600.0;
    //    std::cout << '\n' << "В часах это: " << hours_time << "часа(ов)";
    //    std::cout << '\n' << "В секундах это: " << seconds_time << "секунд(ы)";
    //}

    //{
    //    std::cout << '\n' << "Second Task" << '\n';
    //    std::cout << "Введите денежную дробь для ее конвертации в гривны и копейки: ";
    //    float money;
    //    std::cin >> money;
    //    int money_general = money;
    //    int money_small = (money - money_general) * 100;
    //    std::cout << '\n' << "В гривнах: " << money_general << '\n';
    //    std::cout << '\n' << "В копейках: " << money_small << '\n';
    //}

    {
        std::cout <<'\n' << "Third Task" << '\n';
        std::cout << "Расчет скорости бега" << '\n';
        float distance;
        std::cout << "Введите дисстанцию в метрах: ";
        std::cin >> distance;
        float time;
        std::cout << "Введите время (мин.сек): ";
        std::cin >> time;
        std::cout << "\nДисстанция: " << (int)distance << "м.\n";
        int seconds = (time - (int)time) * 100;
        float allseconds = (int)time * 60 + seconds;
        std::cout << "Время: " << (int)time << "мин " << seconds << "сек " << "= " << (int)allseconds << "сек.\n";
        float kilometres = distance / 1000;
        float hours = allseconds / 3600;
        std::cout << "Вы бежали со скоростью " << kilometres / hours << "км/час";
    }
}

