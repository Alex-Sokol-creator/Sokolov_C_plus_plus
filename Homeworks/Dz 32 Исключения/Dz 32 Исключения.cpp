
#include <iostream>
#include <Windows.h>
#include <string>

class InvalidAmountException : public std::runtime_error {
public:
    InvalidAmountException(const char* message) : std::runtime_error(message) {};
    ~InvalidAmountException() = default;

    //const char* what() const noexcept override {
    //    return "Invalid Amount error!\n";
    //}
};

class InsufficientFundsException : public std::runtime_error {
public:
    InsufficientFundsException(const char* message) : std::runtime_error(message) {};
    ~InsufficientFundsException() = default;

    //const char* what() const noexcept override {
    //    return "Insufficient Funds error!\n";
    //}
};

class LimitExceededException : public std::runtime_error {
public:
    LimitExceededException(const char* message) : std::runtime_error(message) {};
    ~LimitExceededException() = default;

    //const char* what() const noexcept override {
    //    return "Limit Exceeded error!\n";
    //}
};

class ATM {
private:
    int balance;
    int dailyLimit;
    int withdrawnToday;
public:
    ATM() : balance(0), dailyLimit(0), withdrawnToday(0) {};
    ATM(int balance, int dailyLimit, int withdrawnToday) : balance(balance), dailyLimit(dailyLimit), withdrawnToday(withdrawnToday) {};

    void withdraw(int amount) {
        while (amount <= 0) {
            std::cout << "Количество денег не может быть меньше или равняться 0, введите другую сумму: ";
            std::cin >> amount;
        }
        if (amount % 100 != 0) {
            throw InvalidAmountException("Invalid Amount of Money");
        }
        else if (amount > balance) {
            throw InsufficientFundsException("Insufficient Funds");
        }
        else if (withdrawnToday + amount > dailyLimit) {
            throw LimitExceededException("Daily limit exceeded");
        }
        else {
            balance -= amount;
            withdrawnToday += amount;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ATM Atm(5000, 3400, 100);
    bool MovingPrograme = true;
    int amount;
    std::cout << "Введите желаемую сумму для снятия: ";
    std::cin >> amount;
    try {
        Atm.withdraw(amount);
    }
    catch (const InvalidAmountException& e) { std::cout << e.what() << '\n'; MovingPrograme = false; }
    catch (const InsufficientFundsException& e) { std::cout << e.what() << '\n'; MovingPrograme = false; }
    catch (const LimitExceededException& e) { std::cout << e.what() << '\n'; MovingPrograme = false; }
    catch (const std::runtime_error& e) { std::cout << e.what() << '\n';; MovingPrograme = false; }
    catch (...) { std::cout << "Unknown error\n"; MovingPrograme = false; }
    if (MovingPrograme) {
        std::cout << "Операция прошла успешно!\n";
        std::cout << "До свидания!";
    }
    else {
        std::cout << "Ошибка, попробуйте заново";
    }
}

