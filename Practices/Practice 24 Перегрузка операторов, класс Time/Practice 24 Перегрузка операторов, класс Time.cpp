
#include <iostream>
#include <Windows.h>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        int add_minutes, add_hours;
        if (seconds >= 60) {
            add_minutes = seconds / 60;
            seconds = seconds % 60;
            minutes = minutes + add_minutes;
        }
        if (minutes >= 60) {
            add_hours = minutes / 60;
            minutes = minutes % 60;
            hours = hours + add_hours;
        }
    }
public:
     Time() : seconds(0), minutes(0), hours(0) {}

     Time(int seconds, int minutes, int hours) : seconds(seconds), minutes(minutes), hours(hours) { normalize(); }

     Time operator+(const Time& other) {
         int new_hours = hours + other.hours, new_minutes = minutes + other.minutes, new_seconds = seconds + other.seconds;
         return Time(new_seconds, new_minutes, new_hours);
     }

     Time operator-(const Time& other) {
         int t1 = hours * 3600 + minutes * 60 + seconds;
         int t2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
         if (t1 < t2) {
             return Time(0, 0, 0);
         }
         else {
             return Time((t1 - t2), 0, 0);
         }
     }

     friend std::ostream& operator<<(std::ostream& out, const Time& current_time) {
         out << current_time.hours << " : " << current_time.minutes << " : " << current_time.seconds << '\n';
         return out;
     }

     friend std::istream& operator>>(std::istream& in, Time& current_time) {
         char slesh;
         in >> current_time.seconds >> slesh >> current_time.minutes >> slesh >> current_time.hours;
         current_time.normalize();
         return in;
     }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "--- Тест 1: Инициализация и нормализация ---" << std::endl;
    Time t1(65, 59, 1);
    std::cout << "Время t1 (введено 65с, 59м, 1ч): " << t1 << std::endl;

    Time t2(30, 15, 0);
    std::cout << "Время t2 (введено 30с, 15м, 0ч): " << t2 << std::endl;
    std::cout << std::endl;

    std::cout << "--- Тест 2: Сложение (t1 + t2) ---" << std::endl;
    Time t_sum = t1 + t2;
    std::cout << t1 << " + " << t2 << " = " << t_sum << std::endl;
    std::cout << std::endl;

    std::cout << "--- Тест 3: Вычитание (t1 - t2) ---" << std::endl;
    Time t_diff1 = t1 - t2;
    std::cout << t1 << " - " << t2 << " = " << t_diff1 << std::endl;

    std::cout << "--- Тест 4: Вычитание в минус (t2 - t1) ---" << std::endl;
    Time t_diff2 = t2 - t1;
    std::cout << t2 << " - " << t1 << " = " << t_diff2 << std::endl;
    std::cout << std::endl;

    std::cout << "--- Тест 5: Ввод с клавиатуры ---" << std::endl;
    Time t_input;
    std::cout << "Введите время в вашем формате (Секунды:Минуты:Часы), например, 75:20:1: ";
    std::cin >> t_input;
    std::cout << "Результат ввода (с нормализацией): " << t_input << std::endl;

}

