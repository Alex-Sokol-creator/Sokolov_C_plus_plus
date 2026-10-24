
#include <iostream>
#include <Windows.h>
#include <string>
#include <stack>

bool isValid(const std::string& expression) {
    std::stack<char> mystack;
    for (char symbol : expression) {
        if (symbol == '(' || symbol == '[' || symbol == '{') {
            mystack.push(symbol);
        }
        if (symbol == ')' || symbol == ']' || symbol == '}') {
            if (mystack.empty()) {
                return false;
            }
            if ((mystack.top() == '(' && symbol == ')') || (mystack.top() == '[' && symbol == ']') || (mystack.top() == '{' && symbol == '}')) {
                mystack.pop();
            }
            else {
                return false;
            }
        }
    }
    if (mystack.empty()) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        std::string user_str;
        std::cout << "Введите строку для ввода или exit для выхода: ";
        std::getline(std::cin, user_str);
        if (user_str == "exit") {
            break;
        }
        else {
            if (isValid(user_str) == true) { std::cout << "Корректно\n"; }
            else { std::cout << "Ошибка\n"; }
        }
    }

    std::cout << "До свидания!";
}

