
#include <iostream>
#include <Windows.h>
#include <string>

class Audio {
public:
    virtual ~Audio() = default;

    virtual void Play() const {};
};

class Song : public Audio {
private:
    std::string title;
    std::string artist;
public:
    Song() : title(""), artist("") {};
    Song(std::string title, std::string artist) : title(title), artist(artist) {};

    void Play() const override {
        std::cout << "Playing song: " << title << " by " << artist << '\n';
    }
};

class Podcast : public Audio {
private:
    std::string host;
    std::string topic;
public:
    Podcast() : host(""), topic("") {};
    Podcast(std::string host, std::string topic) : host(host), topic(topic) {};

    void Play() const override {
        std::cout << "Podcast on " << topic << " hosted by " << host << '\n';
    }
};

class Audiobook : public Audio {
private:
    std::string bookTitle;
    std::string author;
    std::string voice;
public:
    Audiobook() : bookTitle(""), author(""), voice("") {};
    Audiobook(std::string bookTitle, std::string author, std::string voice) : bookTitle(bookTitle), author(author), voice(voice) {};

    void Play() const override {
        std::cout << "Listening to audiobook : " << bookTitle << " by " << author << ".Read by " << voice << ".\n";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        int choice = 0;
        while (choice <= 0 || choice > 4) {
            std::cout << "Выберите тип аудио: \n1. Song\n2. Podcast\n3. Audiobook\n4. Exit\n>";
            std::cin >> choice;
        }
        std::cin.ignore();
        switch (choice) {
        case 1: {
            std::string title;
            std::string artist;
            std::cout << "Введите название песни: ";
            std::getline(std::cin, title);
            std::cout << "Введите исполнителя: ";
            std::getline(std::cin, artist);
            Song song = Song(title, artist);
            song.Play();
            break;
        }
        case 2: {
            std::string host;
            std::string topic;
            std::cout << "Введите автора: ";
            std::getline(std::cin, host);
            std::cout << "Введите тему: ";
            std::getline(std::cin, topic);
            Podcast song = Podcast(host, topic);
            song.Play();
            break;
        }
        case 3: {
            std::string bookTitle;
            std::string author;
            std::string voice;
            std::cout << "Введите название книги: ";
            std::getline(std::cin, bookTitle);
            std::cout << "Введите автора: ";
            std::getline(std::cin, author);
            std::cout << "Введите голос: ";
            std::getline(std::cin, voice);
            Audiobook song = Audiobook(bookTitle, author, voice);
            song.Play();
            break;
        }
        }
        if (choice == 4) {
            std::cout << "До свидания!";
            break;
        }
    }
}

