#pragma once
#include <vector>

struct Test;

class TestAttempt {
private:
	int current_question = 0;
	int correct_answers = 0;
	double right_percentage = 0.0;
	int result_grade = 0;
	bool ongoing_test = false;
	bool paused = false;
	bool finished = false;
	std::vector<int> user_answers;
public:
	TestAttempt() = default;
	TestAttempt(int current_question, int correct_answers, double right_percentage, int result_grade, bool ongoing_test, const std::vector<int>& user_answers);

	void StartTest(const Test& selected_test); // Начало теста
	void ContinueTest(const Test& selected_test); // Продолжение ( если ongoing == true)
	void StopTest(); // Стоп теста
	void CalculateResult(const Test& selected_test); // Подсчет результата
	void RunQuestions(const Test& selected_test);

	int GetCorrectAnswers() const;
	double GetRightPercentage() const;
	int GetResultGrade() const;
	bool IsFinished() const;
};

