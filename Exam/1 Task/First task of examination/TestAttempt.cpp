#include "TestAttempt.h"
#include "Tests.h"
#include <iostream>
#include <cmath>

void TestAttempt::RunQuestions(const Test& selected_test)
{
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

            std::cout << "Выберите существующий вариант ответа!\n";
        }

        // Запоминаем индекс выбранного ответа.
        user_answers[current_question] = choice - 1;

        current_question++;
    }

    // Все вопросы пройдены.
    ongoing_test = false;
    paused = false;

    std::cout << "\nТест завершен!\n";

    CalculateResult(selected_test);
}

void TestAttempt::StartTest(const Test& selected_test)
{
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
