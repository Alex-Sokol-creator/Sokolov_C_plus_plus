//Dz 1 moved

#include <iostream>
#include <Windows.h>

int main()
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    {
        std::cout << "First Task" << '\n';
        std::cout << "Введите время в секундах для их конвертации: ";
        long seconds_time;
        std::cin >> seconds_time;
        float minuts_time = seconds_time / 60.0;
        std::cout << '\n' << "В минутах это: " << minuts_time << "минут(ы)";
        float hours_time = seconds_time / 3600.0;
        std::cout << '\n' << "В часах это: " << hours_time << "часа(ов)";
        std::cout << '\n' << "В секундах это: " << seconds_time << "секунд(ы)";
    }

    {
        std::cout << '\n' << "Second Task" << '\n';
        std::cout << "Введите денежную дробь для ее конвертации в гривны и копейки: ";
        float money;
        std::cin >> money;
        int money_general = money;
        int money_small = (money - money_general) * 100;
        std::cout << '\n' << "В гривнах: " << money_general << '\n';
        std::cout << '\n' << "В копейках: " << money_small << '\n';
    }

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

    {
        std::cout << '\n' << "Fourth Task" << '\n';
        int days;
        std::cout << "Введите количество дней для конвертации в недели: ";
        std::cin >> days;
        int weeks = days / 7;
        int days_last = days - (weeks * 7);
        std::cout << "Это будет в неделях: " << weeks << " , и еще останется дней: " << days_last << '\n';
    }

    {
        std::cout << '\n' << "Fifth Task" << '\n';
        float distance;
        std::cout << "Введите расстояние до аэропорта в километрах: ";
        std::cin >> distance;
        std::cout << "\nВведите время, за которое туда надо добраться (0 - в минутах,1 - в часах): ";
        float time;
        int choice;
        std::cin >> choice;
        if (choice == 0) {
        std::cout << "\nВведите время в минутах: ";
        std::cin >> time;
        std::cout << "\nЧтобы доехать в аэропорт за это время и с этим расстоянием, вам надо ехать со скоростью: " << distance / (time/60) << "км/час";
        }
        else if (choice == 1) {
        std::cout << "\nВведите время в часах: ";
        std::cin >> time;
        std::cout << "\nЧтобы доехать в аэропорт за это время и с этим расстоянием, вам надо ехать со скоростью: " << distance / time << "км/час";
        }
        else {
            std::cout << "Вы ввели неправильную цифру, попробуйте снова";
        }
    }

    {
        std::cout << '\n' << "Sixth Task" << '\n';
        float distance;
        std::cout << "Введите расстояние в километрах, которое надо преодолеть: ";
        std::cin >> distance;
        float spending;
        std::cout << "\nВведите траты бензина на 100 км: ";
        std::cin >> spending;
        float price1;
        float price2;
        float price3;
        std::cout << "\nТеперь введите цену на первый вид бензина: ";
        std::cin >> price1;
        std::cout << "\nВторой вид бензина: ";
        std::cin >> price2;
        std::cout << "\nТретий вид бензина: ";
        std::cin >> price3;
        std::cout << "\nЕсли вы будете ехать " << distance << " км с расходом топлива " << spending << " литров на 100 км и вы купите:\n";
        std::cout << "Первый вид топлива, то вы потратите: " << distance / 100 * spending * price1 << "грн\n";
        std::cout << "Второй вид топлива, то вы потратите: " << distance / 100 * spending * price2 << "грн\n";
        std::cout << "Третий вид топлива, то вы потратите: " << distance / 100 * spending * price3 << "грн";
    }

    {
        std::cout << '\n' << "Seven Task" << '\n';
        int seconds;
        std::cout << "Введите сколько секунд прошло с начала дня: ";
        std::cin >> seconds;
        if (seconds >= 86400) {
            std::cout << "Столько секунд не могло пройти, уже новый день";
        }
        else {
            int hours = seconds / 3600;
            int minuts = (seconds / 60) - (hours * 60);
            int seconds_now = seconds - (hours * 3600) - (minuts * 60);

            int seconds_last = 86400 - seconds;
            int hours_last = seconds_last / 3600;
            int minuts_last = (seconds_last / 60) - (hours_last * 60);
            int seconds_lasted = seconds_last - (hours_last * 3600) - (minuts_last * 60);
            std::cout << "\nСейчас у вас: " << hours << " ч " << minuts << "мин " << seconds_now << "сек\n";
            std::cout << "\nДо полуночи осталось: " << hours_last << " ч " << minuts_last << "мин " << seconds_lasted << "сек\n";
        }
    }

    {
        std::cout << '\n' << "Eighth Task" << '\n';
        int seconds;
        std::cout << "Введите сколько секунд прошло с начала рабочего дня: ";
        std::cin >> seconds;
        if (seconds >= 28800) {
            std::cout << "\nСтолько секунд не могло пройти, вы уже дома";
        }
        else {
            std::cout << "\nДо конца рабочего дня осталось " << (28800 - seconds) / 3600 << " часов\n";
        }
    }
}

