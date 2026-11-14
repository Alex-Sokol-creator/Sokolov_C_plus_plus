#include "TestAttempt.h"
#include "Tests.h"
#include <iostream>
#include <cmath>

TestAttempt::TestAttempt(int current_question, int correct_answers, double right_percentage, int result_grade, bool ongoing_test, const std::vector<int>& user_answers)
    : current_question(current_question), correct_answers(correct_answers), right_percentage(right_percentage),
    result_grade(result_grade), ongoing_test(ongoing_test), user_answers(user_answers){};

void TestAttempt::CalculateResult(const Test& selected_test){
    correct_answers = 0;
    for (int i = 0; i < selected_test.questions.size(); i++) {
        const Question& question = selected_test.questions[i];
        if (i >= user_answers.size() || user_answers[i] == -1) {
            continue;
        }
        int answer_index = user_answers[i];
        if (answer_index < question.answers.size() && question.answers[answer_index].is_correct) {
            correct_answers++;
        }
    }
    int total_questions = static_cast<int>(selected_test.questions.size());
    if (total_questions == 0) {
        return;
    }
    right_percentage = static_cast<double>(correct_answers) / total_questions * 100.0;
    result_grade = static_cast<int>(std::ceil(right_percentage / 100.0 * 12));
    if (result_grade < 1) {
        result_grade = 1;
    }
    if (result_grade > 12) {
        result_grade = 12;
    }
    std::cout << "Результат:\n";
    std::cout << "Правильных ответов: " << correct_answers << " из " << total_questions << '\n';
    std::cout << "Процент правильных ответов: " << right_percentage << "%\n";
    std::cout << "Оценка по 12-балльной системе: " << result_grade << '\n';
}

void TestAttempt::StopTest(){
    if (ongoing_test != true) {
        return;
    }
    paused = true;
    std::cout << "\nТест поставлен на паузу\n";
}

void TestAttempt::ContinueTest(const Test& selected_test){
    if (ongoing_test != true || paused != true) {
        std::cout << "Нет приостановленного теста!\n";
        return;
    }
    paused = false;
    std::cout << "\nТест продолжается\n";
    RunQuestions(selected_test);
}

void TestAttempt::RunQuestions(const Test& selected_test){
    while (current_question < selected_test.questions.size()) {
        const Question& question = selected_test.questions[current_question];
        std::cout << "Вопрос " << current_question + 1 << " из " << selected_test.questions.size() << '\n' << question.text << '\n';
        if (question.answers.empty()) {
            std::cout << "К сожалению, у этого вопроса нет вариантов ответа\n";
            current_question++;
            continue;
        }
        for (int i = 0; i < question.answers.size(); i++) {
            std::cout << i + 1 << ". " << question.answers[i].text << '\n';
        }
        int choice = -1;
        while (true) {
            std::cout << "Ваш ответ (0 - пауза): ";
            std::cin >> choice;
            if (choice == 0) {
                StopTest();
                return;
            }
            if (choice >= 1 && choice <= question.answers.size()) {
                break;
            }
            std::cout << "Выберите нормальный ответ\n";
        }
        user_answers[current_question] = choice - 1;
        current_question++;
    }
    ongoing_test = false;
    paused = false;
    finished == true; // Когда тест закончился
    std::cout << "\nТест завершен!\n";
    CalculateResult(selected_test);
}

void TestAttempt::StartTest(const Test& selected_test){
    if (selected_test.questions.empty()) {
        std::cout << "К сожалению, в этом тесте пока нет вопросов\n";
        return;
    }
    current_question = 0;
    correct_answers = 0;
    right_percentage = 0.0;
    result_grade = 0;
    ongoing_test = true;
    paused = false;
    user_answers.assign(selected_test.questions.size(), -1);
    std::cout << "\n===== НАЧАЛО ТЕСТА =====\n";
    std::cout << "Название теста: " << selected_test.name << '\n';
    std::cout << "Количество вопросов: " << selected_test.questions.size() << '\n';
    RunQuestions(selected_test);
    while (ongoing_test && paused) {
        int choice = 0;
        std::cout << "\nТест приостановлен.\n";
        std::cout << "1. Продолжить тест\n" << "2. Выйти из теста\n" << "Ваш выбор: ";
        std::cin >> choice;
        if (choice == 1) {
            ContinueTest(selected_test);
        }
        else if (choice == 2) {
            ongoing_test = false;
            paused = false;
            std::cout << "Вы вышли из теста.\n";
        }
        else {
            std::cout << "Неправильный выбор\n";
        }
    }
}


int TestAttempt::GetCorrectAnswers() const {
    return correct_answers;
}

double TestAttempt::GetRightPercentage() const {
    return right_percentage;
}

int TestAttempt::GetResultGrade() const {
    return result_grade;
}

bool TestAttempt::IsFinished() const {
    return finished;
}
