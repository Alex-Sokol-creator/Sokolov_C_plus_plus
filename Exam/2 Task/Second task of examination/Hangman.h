#pragma once
#include <vector>
#include <string>

class Hangman
{
private:
    std::string word;
    std::string guessed_word;
    std::vector<char> used_letters;
    int mistakes = 0;
    int attempts = 0;
    bool result = false;
public:
    Hangman(const std::string& word);
    void Play();
};

