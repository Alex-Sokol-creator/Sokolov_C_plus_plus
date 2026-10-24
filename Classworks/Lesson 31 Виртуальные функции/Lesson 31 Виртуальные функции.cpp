#include <iostream>
#include <vector>
#include <memory>

class Animal {
protected:
    std::string name;
    int age;
public:
    Animal(std::string name, int age) : name(name), age(age){}

    virtual void MakeSound() const{
        std::cout << "Animal " << name << " makes abstract sound.\n";
    }
};

class Dog : public Animal {
private:
    std::string breed;
public:
    Dog(std::string name, int age, std::string breed): Animal(name, age),breed(breed){}

    void MakeSound() const override{
        std::cout << "Dog " << name << " says WOOF.\n";
    }
};

class Frog : public Animal{
private:
    std::string colour;
public:
    Frog(std::string name, int age, std::string colour) : Animal(name,age),colour(colour){}

    void MakeSound() const{
        std::cout << "Frog " << name << " says QUA.\n";
    }
};

class Parrot : public Animal {
private:
    std::vector<std::string> words;
public:
    Parrot(std::string name, int age, std::vector<std::string> words) : Animal(name, age), words(words) {}

    void MakeSound() const{
        std::cout << "Parrot " << name << " says: \n";
        for (const std::string& word : words) {
            std::cout << word << ", ";
        }
        std::cout << '\n';
    }
};

class Enemy {
protected:
    int damage;
    int health;
    std::string name;
public:
    Enemy(int damage, int health, std::string name) : damage(damage), health(health), name(name){}

    virtual void Attack() const {
        std::cout << "Abstract enemy makes abstract attack";
    }
};

class Shooter : public Enemy {
private:
    std::string gun;
public:
    Shooter(int damage, int health, std::string name, std::string gun) : Enemy(damage, health, name), gun(gun) {}

    virtual void Attack() const {
        std::cout << "Shooter " << name << " deals " << " with gun " << gun << '\n';;
    }
};

class Bomber : public Enemy {
private:
    float radius;
public:
    Bomber(int damage, int health, std::string name, float radius) : Enemy(damage, health, name), radius(radius) {}

    virtual void Attack() const {
        std::cout << "Bomber " << name << " deals " << " with bomb in radius " << radius << '\n';;
    }
};

class Swordman : public Enemy {
private:
    int distance;
public:
    Swordman(int damage, int health, std::string name, int distance) : Enemy(damage, health, name), distance(distance) {}

    virtual void Attack() const {
        std::cout << "Swordman " << name << " deals " << " with sowrd in distance " << distance << '\n';;
    }
};

class Spawner {
private:
    std::vector<Enemy*> enemies;
public:
    ~Spawner() {
        if (enemies.size() > 0) {
            for (int i = 0; i < enemies.size(); i++) {
                delete enemies[i];
            }
        }
    }

    Enemy* SpawnEnemy() {
        Enemy* enemy = nullptr;

        switch (rand() % 3) {
        case 0: enemy = new Shooter(40, 15, "Shooter", "Shotgun");
            break;
        case 1: enemy = new Bomber(60, 10, "Bomber", 45.5);
            break;
        case 2: enemy = new Swordman(25, 5, "Swordman", 2);
            break;
        }

        enemies.push_back(enemy);
        return enemy;
    }
};

int main()
{
    srand(time(NULL));

    /*
    std::vector<std::unique_ptr<Animal>> animals; 
    animals.push_back(std::make_unique<Dog>("Jack", 4, "Golden Retriver"));
    animals.push_back(std::make_unique<Frog>("Yosyp", 2, "Purple"));
    animals.push_back(std::make_unique<Parrot>("Danylo", 4, std::vector<std::string>{ "Hello","incapsulation","javascript" }));

    for (int i = 0; i < 3; i++) {
        animals[i]->MakeSound();
    }

    Animal* animal = nullptr;
    int type;
    std::cout << "Choose animal: ";
    std::cin >> type;
    switch (type) {
    case 1: 
        animal = new Dog("Jack", 4, "Golden Retriver"); break;
    case 2: 
        animal = new Frog("Yosyp", 2, "Purple"); break;
    case 3: 
        animal = new Parrot("Danylo", 4, std::vector<std::string>{ "Hello", "incapsulation", "javascript" }); break;
    }

    if (animal != nullptr) {
        animal->MakeSound();
        delete[] animal;
    }
    */

    Spawner spawner;

    const int MAX_ENEMIES = 5;
    Enemy* enemies[MAX_ENEMIES];
    int enemyCount = 0;
    while (enemyCount < MAX_ENEMIES) {
        enemies[enemyCount++] = spawner.SpawnEnemy();
    }

    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i]->Attack();
        std::cout << '\n';
    }

    //Dog dog("Jack", 4, "Golden Retriver");

    //dog.MakeSound();
}

