#include "Hangman.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>
#include <fstream>

Hangman::Hangman(const std::string& word) {
	this->word = word;
	guessed_word = std::string(word.length(), '_');
}

void Hangman::Play() {
	std::cout << "\n=====HANGMAN GAME=====\n";
	std::cout << "Компьютер загадал слово, попробуйте его угадать, у вас 6 попыток, игра заканчивается, если вы потратили все попытки или же вы победили\nУдачи!\n";
	time_t start_time = time(0); // Берет время начала игры
	while (mistakes < 6 && result == false) {
		std::cout << "Ваше слово: " << guessed_word << '\n';
		std::cout << "Количество ошибок: " << mistakes << "\n\n";
		char Users_letter;
		while (true) {
			std::cout << "Введите букву для отгадывания: ";
			std::cin >> Users_letter;
			Users_letter = static_cast<char>(std::tolower(static_cast<unsigned char>(Users_letter)));
			if (Users_letter < 'a' || Users_letter > 'z') {
				std::cout << "Введите английскую букву!\n";
				continue;
			}
			bool WasUsed = false;
			for (char used_letter : used_letters) {
				if (used_letter == Users_letter) {
					std::cout << "Такая буква уже была, напишите другую\n";
					WasUsed = true;
					break;
				}
			}
			if (WasUsed == false) {
				used_letters.push_back(Users_letter);
				attempts++;
				break;
			}
		}
		int index = 0;
		bool WasFound = false;
		for (char letter_in_word : word) {
			if (letter_in_word == Users_letter) {
				guessed_word[index] = Users_letter;
				WasFound = true;
			}
			index++;
		}
		if (WasFound != true) {
			std::cout << "К сожалению, такой буквы нет в слове, -1 попытка\n";
			mistakes++;
		}
		if (guessed_word == word) {
			result = true;
		}
	}
	time_t end_time = time(0); // Берет время окончания игры
	double game_time = difftime(end_time, start_time); // Вычитает от конца начало, и мы получаем время нашего отгадывания
	if (result == false) {
		std::cout << "К сожалению, вы проиграли, вы повешены\n";
	}
	else {
		std::cout << "Поздравляем! Вы отгадали слово! Это было: " << word << '\n';
	}
	std::cout << "\n===== ИГРОВАЯ СТАТИСТИКА =====\n";
	std::cout << "Время игры: " << game_time << " секунд\n";
	std::cout << "Количество попыток: " << attempts << '\n';
	std::cout << "Количество ошибок: " << mistakes << '\n';
	std::cout << "Загаданное слово: " << word << '\n';
	std::cout << "Все введённые вами буквы: ";
	for (char letter : used_letters) {
		std::cout << letter << ' ';
	}
	std::cout << '\n';

	// Сохранение результата в файл
	std::ofstream file("statistics.txt", std::ios::app);
	if (file.is_open()) {
		file << "===== ИГРОВАЯ СТАТИСТИКА =====\n";
		file << "Результат: ";
		if (result == true) {
			file << "Победа\n";
		}
		else {
			file << "Проигрыш\n";
		}

		file << "Время игры: " << game_time << " секунд\n";
		file << "Попытки: " << attempts << '\n';
		file << "Ошибки: " << mistakes << '\n';
		file << "Слово: " << word << '\n';
		file << "Использованные буквы: ";
		for (char letter : used_letters) {
			file << letter << ' ';
		}
		file << "\n\n";
		file.close();
		std::cout << "Статистика сохранена в файл!\n";
	}
	else {
		std::cout << "Не удалось открыть файл статистики!\n";
	}
}