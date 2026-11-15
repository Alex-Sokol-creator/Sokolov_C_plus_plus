#include <iostream>
#include <Windows.h>
#include "WordManager.h"
#include "Hangman.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(NULL));
    WordManager manager;
    manager.LoadWords();
    std::string word = manager.GetRandomWord();
    if (word.empty()) {
        std::cout << "Не удалось получить слово!\n";
        return 1;
    }
    Hangman game(word);
    game.Play();
}

