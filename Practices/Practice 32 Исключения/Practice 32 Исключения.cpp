
#include <iostream>
#include <Windows.h>
#include <string>

int toInt(const std::string& s) {
    size_t position;
    int num = std::stoi(s, &position);
    if (position == s.length()) {
        return num;
    }
    else {
        throw std::invalid_argument("Your string is not a number!");
    }
}

class BadPassword : public std::runtime_error {
public:
    BadPassword(const std::string message) : std::runtime_error(message) {};
    ~BadPassword() = default;

    //const char* what() const noexcept override {
    //    return "Your password is not appropriate due to rules!\n";
    //}
};

void CheckPassword(const std::string& password) {
    if (password.length() < 8) {
        throw BadPassword("Your password is not appropriate due to rules!\n");
    }
    bool numFlag = false;
    for (char symbol : password) {
        if (isdigit(symbol)) {
            numFlag = true;
            break;
        }
    }
    if (numFlag == false) {
        throw BadPassword("Your password is not appropriate due to rules!\n");
    }
    else {
        std::cout << "Your password is good and appropriate\n";
    }
}

//class AgeExceptionError : public std::runtime_error {
//public:
//    AgeExceptionError(const std::string message) : std::runtime_error(message) {};
//    ~AgeExceptionError() = default;
//};
//
//class AgeException {
//private:
//    std::string candidate;
//    int age;
//public:
//    AgeException() : candidate(""), age(0) {};
//    AgeException(std::string candidate, int age) : candidate(candidate), age(age) {};
//
//    void vote(std::string candidate, int age) {
//        if (age < 18) {
//            throw AgeExceptionError("Candidate`s age is less than 18 years\n");
//        }
//    }
//};


class AgeException : public std::runtime_error {
public:
    AgeException(int age) : std::runtime_error("Age of a candidat is less than 18!\n") {};
};

void vote(std::string candidate, int age) {
    if (age < 18) {
        throw AgeException(age);
    }
    else {
        std::cout << candidate << " is allowed to vote!\n";
    }
}

int main()
{
    try {
        std::cout << "Number: " << toInt("123") << '\n';
    }
    catch (const std::invalid_argument& ex) {
        std::cout << ex.what();
    }

    try {
        CheckPassword("Hello123");
    }
    catch (const BadPassword& ex) {
        std::cout << ex.what();
    }

    try {
        vote("Alex", 17);
    }
    catch (const AgeException& ex) {
        std::cout << ex.what();
    }
}

