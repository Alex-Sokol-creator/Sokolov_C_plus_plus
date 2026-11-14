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

	void ChooseAction(); // Выбор действия (посмотреть, пройти новое)

	void ChooseCategory(); // Выбор категории теста
	void ChooseTest(); // Выбор конкретного теста

	void LookPrevious(); // Посмотреть прошлые тесты
};

class TestAttempt {
private:
	int current_question = 0;
	int correct_answers = 0;
	double right_percentage = 0.0;
	int result_grade = 0;
	bool ongoing_test = false;
	std::vector<int> user_answers;
public:
	TestAttempt() = default;
	TestAttempt(int current_question, int correct_answers, double right_percentage, int result_grade, bool ongoing_test, const std::vector<int>& user_answers);

	void StartTest(); // Начало теста
	void ContinueTest(); // Продолжение ( если ongoing == true)
	void StopTest(); // Стоп теста
	void CalculateResult(); // Подсчет результата
	void SaveResult(); // Сохранение результата
};

