#pragma once
#include <vector>
#include <string>

class WordManager
{
private:
    std::vector<std::string> words;
    std::string UncodeWord(const std::string& coded_word) const;
public:
    void LoadWords();
    std::string GetRandomWord() const;
};

