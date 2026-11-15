#include "WordManager.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

std::string WordManager::UncodeWord(const std::string& coded_word) const {
	std::string result;
	for (char symbol : coded_word) {
		char decrypted_letter = (symbol - 'a' - 3 + 26) % 26 + 'a';
		result += decrypted_letter;
	}
	return result;
}

void WordManager::LoadWords() {
    std::ifstream file("words.txt");
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!\n";
        return;
    }
    std::string coded_word;
    while (file >> coded_word) {
        words.push_back(UncodeWord(coded_word));
    }
    file.close();
    std::cout << "Слова успешно загружены\n";
}

std::string WordManager::GetRandomWord() const {
    if (words.empty()) {
        return "";
    }
    int random_index = rand() % words.size();
    return words[random_index];
}