
#include <iostream>
#include <Windows.h>
#include <string>
#include <format>

std::wstring utf8_to_utf16(const std::string& utf8str) {
    if (utf8str.empty())
        L"";

    int size = MultiByteToWideChar(CP_UTF8, 0, utf8str.c_str(), -1, nullptr, 0);
    std::wstring result(size, 0);

    MultiByteToWideChar(CP_UTF8, 0, utf8str.c_str(), -1, &result[0], size);
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str = "Hello, world!";

    std::cout << str << '\n';

    std::cout << str[2] << '\n';

    str[2] = 'o';
    std::cout << str << '\n';
    std::cout << str.at(3) << '\n';

    str.at(4) = '-';
    std::cout << str << '\n';

    // std::cout << str[15] << '\n';

    // std::cout << str.at(15) << '\n';

    std::string str2 = str + " Goodbye!";
    std::cout << str2 << '\n';

    str += "I love C++";
    std::cout << str << '\n';

    str.append("and hate JavaScript");
    std::cout << str << '\n';

    std::cout << str.size() << ' ' << str.length() << ' ' << str.capacity() << '\n';
    
    std::string emptyString = "";

    std::cout << emptyString.empty() ? "string is empty" : "string is not empty"; 
    std::cout << '\n';

    auto position = str.find("world");
    if (position != std::string::npos) {
        std::cout << position;
    }
    else {
        std::cout << ", is not in str";
    }

    std::string world = str.substr(position, 5);
    std::cout << '\n' << world << '\n';

    str.erase(3, 3);
    std::cout << str << '\n';

    str.replace(7, 5, "P56");
    std::cout << str << '\n';

    str.insert(5, "JavaScript");
    std::cout << str << '\n';

    std::string numS = "145";
    int numInt = std::stoi(numS);
    double numDouble = std::stod(numS);
    std::cout << numInt << '\n';
    std::cout << numDouble << '\n';

    int num = 1234;
    std::string numString = std::to_string(num);
    std::cout << numString << '\n';

    std::string userName;
    // std::getline(std::cin, userName);
    userName = "Vova";

    int age;
    // std::cin.ignore();
    std::cin >> age;
    std::cout << userName << '\n' << age << '\n';

    std::string ersult = std::format("User {} age {}", userName, age);
    std::cout << userName << '\n' << age << '\n';

    std::string strSlavic = "Привет";
    std::cout << str.size() << '\n';
    std::cout << strSlavic << '\n';

    std::string message = "Привіт, це повідомлення українською мовою";
    std::string title = "Успішна конвертація";

    std::wstring wMessage = utf8_to_utf16(message);
    std::wstring wTitle = utf8_to_utf16(title);

    MessageBoxW(nullptr, wMessage.c_str(), wTitle.c_str(), MB_OK | MB_ICONINFORMATION);


}

