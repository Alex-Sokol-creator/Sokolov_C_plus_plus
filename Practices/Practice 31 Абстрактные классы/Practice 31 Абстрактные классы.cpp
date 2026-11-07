
#include <iostream>
#include <Windows.h>
#include <string>

class HomeAnimal {
protected:
    std::string name;
    int health;
public:
    HomeAnimal() : name(""), health(0) {};
    HomeAnimal(std::string name, int health) : name(name), health(health) {};
    virtual ~HomeAnimal() = default;
    
    virtual void Sound() = 0;
    void Show() const {
        std::cout << "This animal has a name: " << name << '\n';
    }
    virtual void Type() = 0;
};

class Dog : public HomeAnimal {
private:
    double RunSpeed;
public:
    Dog(std::string name, int health, double RunSpeed) : HomeAnimal(name, health), RunSpeed(RunSpeed) {};

    void Sound() override {
        std::cout << "Wooooow!\n";
    }
    void Type() override {
        std::cout << "Home dog\n";
    }
};

class Cat : public HomeAnimal {
private:
    double JumpHeight;
public:
    Cat(std::string name, int health, double JumpHeight) : HomeAnimal(name, health), JumpHeight(JumpHeight) {};

    void Sound() override {
        std::cout << "Meeewwwwwwwww!\n";
    }
    void Type() override {
        std::cout << "Home cat\n";
    }
};

class Parrot : public HomeAnimal {
private:
    int Vocabulary;
public:
    Parrot(std::string name, int health, int Vocabulary) : HomeAnimal(name, health), Vocabulary(Vocabulary) {};

    void Sound() override {
        std::cout << "One thousand craps!\n";
    }
    void Type() override {
        std::cout << "Cacapo\n";
    }
};

class Hamster : public HomeAnimal {
private:
    int IQ;
public:
    Hamster(std::string name, int health, int IQ) : HomeAnimal(name, health), IQ(IQ) {};

    void Sound() override {
        std::cout << "~~~~~~~~pspspspsppspsp~~~!\n";
    }
    void Type() override {
        std::cout << "Sirius hamster\n";
    }
};


class Employer {
protected:
    int workStage;
    int age;
    std::string CountryOfOrigin;
    std::string name;
public:
    Employer() : workStage(0), age(0), CountryOfOrigin(""), name("") {};
    Employer(int workStage, int age, std::string CountryOfOrigin, std::string name) 
        : workStage(workStage), age(age), CountryOfOrigin(CountryOfOrigin), name(name) {};
    virtual ~Employer() = default;

    virtual void Print() = 0;
};

class President : public Employer {
public:
    President(int workStage, int age, std::string CountryOfOrigin, std::string name) : Employer(workStage, age, CountryOfOrigin, name) {};

    void Print() override {
        std::cout << "This is Mr. President " << name << ", his/her age is " << age << ".\nHis/her mission is to develop country and be a powerful and wisdom leader\n";
    }
};

class Manager : public Employer {
public:
    Manager(int workStage, int age, std::string CountryOfOrigin, std::string name) : Employer(workStage, age, CountryOfOrigin, name) {};

    void Print() override {
        std::cout << "This is manager " << name << ", his/her age is " << age << ".\nHe/she control different things, operate them and is a very meaningful person\n";
    }
};

class Worker : public Employer {
public:
    Worker(int workStage, int age, std::string CountryOfOrigin, std::string name) : Employer(workStage, age, CountryOfOrigin, name) {};

    void Print() override {
        std::cout << "This is a worker " << name << ", his/her age is " << age << ".\nWorker does some job, it can be simple, but nothing can be without them\n";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Dog dog("Kasper", 100, 6.7);
    Cat cat("Murka", 90, 2.5);
    Parrot parrot("Kesha", 80, 150);
    Hamster hamster("Homa", 70, 10);

    std::cout << "===== HOME ANIMALS =====\n";

    dog.Show();
    dog.Sound();
    dog.Type();

    cat.Show();
    cat.Sound();
    cat.Type();

    parrot.Show();
    parrot.Sound();
    parrot.Type();

    hamster.Show();
    hamster.Sound();
    hamster.Type();

    President president(20, 55, "USA", "Donald");
    Manager manager(10, 35, "Germany", "Alex");
    Worker worker(5, 25, "Poland", "John");

    std::cout << "\n===== EMPLOYERS =====\n";

    president.Print();

    std::cout << '\n';

    manager.Print();

    std::cout << '\n';

    worker.Print();
}

