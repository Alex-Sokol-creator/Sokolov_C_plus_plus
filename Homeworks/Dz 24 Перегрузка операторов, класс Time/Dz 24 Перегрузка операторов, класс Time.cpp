
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



    bool operator==(const Time& right) const {
        return (hours == right.hours) &&
            (minutes == right.minutes) &&
            (seconds == right.seconds);
    }

    std::strong_ordering operator<=>(const Time& right) const {
        if ((hours <=> right.hours) != 0) { return (hours <=> right.hours); }
        else {
            if ((minutes <=> right.minutes) != 0) { return (minutes <=> right.minutes); }
            else {
                return (seconds <=> right.seconds);
            }
        }
    }

    Time& operator++() {
        seconds++;
        normalize();
        return *this;
    }

    Time operator++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    Time& operator--() {
        if (hours == 0 && minutes == 0 && seconds == 0) { return *this; }
        int all_seconds = hours * 3600 + minutes * 60 + seconds;
        all_seconds--;
        hours = 0, minutes = 0;
        seconds = all_seconds;
        normalize();
        return *this;
    }

    Time operator--(int) {
        Time temp = (*this);
        --(*this);
        return temp;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Time t1(59, 59, 1);
    Time t2(0, 0, 2);

    std::cout << "--- Исходное время ---" << std::endl;
    std::cout << "t1 = " << t1;
    std::cout << "t2 = " << t2 << std::endl;

    std::cout << "--- Тест сравнения ---" << std::endl;
    if (t1 < t2)  std::cout << "t1 меньше t2 (Работает <=>)" << std::endl;
    if (t2 > t1)  std::cout << "t2 больше t1 (Работает <=>)" << std::endl;
    if (t1 != t2) std::cout << "t1 не равно t2 (Работает ==)" << std::endl;

    Time t3(59, 59, 1);
    if (t1 == t3) std::cout << "t1 равно t3 (Работает ==)" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Тест инкремента (++) ---" << std::endl;
    std::cout << "Префиксный ++t1 (должно стать 02:00:00 с нормализацией):" << std::endl;
    std::cout << "Результат: " << ++t1;

    std::cout << "Постфиксный t1++ (выведет старое 02:00:00, но увеличит в фоне):" << std::endl;
    std::cout << "Результат в строке: " << t1++;
    std::cout << "Значение после строки (02:00:01): " << t1 << std::endl;

    std::cout << "--- Тест декремента (--) ---" << std::endl;
    Time t4(0, 0, 0);
    std::cout << "Префиксный --t1 (было 02:00:01, станет 02:00:00):" << std::endl;
    std::cout << "Результат: " << --t1;

    std::cout << "Постфиксный t1-- (выведет 02:00:00, но уменьшит до 01:59:59):" << std::endl;
    std::cout << "Результат в строке: " << t1--;
    std::cout << "Значение после строки (01:59:59): " << t1;

    std::cout << "Проверка защиты от ухода ниже нуля (было 00:00:00):" << std::endl;
    std::cout << "Результат: " << --t4;
}
