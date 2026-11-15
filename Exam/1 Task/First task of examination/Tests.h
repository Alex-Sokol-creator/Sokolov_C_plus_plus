#pragma once

#include <vector>
#include <string>

struct Answer {
	std::string text;
	bool is_correct;
};

struct Question {
	std::string text;
	std::vector<Answer> answers;
};

struct Test {
	int id;
	std::string name;
	std::vector<Question> questions;
};

struct Category {
	std::string name;
	std::vector<Test> tests;
};

class Tests
{
private:
	std::vector<Category> categories;
public:
	// настройка класса

	const Category* ChooseCategory() const; // Выбор категории теста
	const Test* ChooseTest(const Category& category) const; // Выбор конкретного теста
	void AddCategory(const Category& category); // Добавить категорию
	void DeleteCategory(int index); // Удалить категорию
	const std::vector<Category>& GetCategories() const; // Взять категории
	void AddTest(int category_index, const Test& test); // Добавить тест
	void DeleteTest(int category_index, int test_index); // Удалить тест
	void AddQuestion(int category_index, int test_index, const Question& question); // Добавить вопрос
};

