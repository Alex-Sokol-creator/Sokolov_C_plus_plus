
#include <iostream>
#include <Windows.h>

class Notification {
protected:
    std::string message;
    std::string timestamp;
public:
    Notification() : message(""), timestamp("") {}

    Notification(std::string message, std::string timestamp) : message(message), timestamp(timestamp) {}
};

class EmailNotification : public Notification {
private:
    std::string emailAddress;
public:
    EmailNotification(std::string message, std::string timestamp, std::string emailAdress) : Notification(message, timestamp), emailAddress(emailAdress) {}

    void send() {
        std::cout << "Отправление email на " << emailAddress << ": " << message << '\n';
    }
};

class PushNotification : public Notification {
private:
    std::string deviceId;
public:
    PushNotification(std::string message, std::string timestamp, std::string deviceId) : Notification(message, timestamp), deviceId(deviceId) {}

    void send() {
        std::cout << "Отправление пуша на устройство " << deviceId << ": " << message << '\n';
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    EmailNotification email("Привет! Это тест.", "30.10.2026", "test@mail.com");
    email.send();

    PushNotification push("Новое уведомление", "30.10.2026", "device_777");
    push.send();
}

