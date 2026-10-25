
#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <cctype>

void StrToLowerRegister(std::string& MyString) {
    for (char& symbol : MyString) {
        symbol = std::tolower(symbol);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string MostCommonWord;
    int MostCommonWordAmount = 0;

    std::string MyText;
    std::string currentWord = "";
    std::cout << "Enter your sentence please: ";
    std::getline(std::cin, MyText);
    StrToLowerRegister(MyText);
    std::map<std::string, int> WordCounter;
    for (char symbol : MyText) {
        if (symbol != ' ' && (symbol != '.' && symbol != ',' && symbol != ';' && symbol != ':' && symbol != '?' && symbol != '!')) {
            currentWord += symbol;
        }
        else {
            if (!currentWord.empty()) {
                WordCounter[currentWord]++;
                currentWord = "";
            }
        }
    }
    if (!currentWord.empty()) {
        WordCounter[currentWord]++;
        currentWord = "";
    }

    for (const auto& [word, count] : WordCounter) {
        std::cout << word << " -> " << count << '\n';
    }

    for (const auto& [word, count] : WordCounter) {
        if (count > MostCommonWordAmount) {
            MostCommonWordAmount = count;
            MostCommonWord = word;
        }
    }
    std::cout << "Most common word in your sentence: " << MostCommonWord << " and it was " << MostCommonWordAmount << " time(s)\n";
}

