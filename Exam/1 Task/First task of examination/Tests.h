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

	void LookPrevious(); // Посмотреть прошлые тесты
	void AddCategory(const Category& category);
};

