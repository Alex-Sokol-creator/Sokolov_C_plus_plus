#include "SystemLogic.h"
#include <iostream>
#include <vector>
#include <string>


SystemLogic::SystemLogic(){
    Category C_plus_plus;
    C_plus_plus.name = "C++";
    Test C_plus_plus_test;
    C_plus_plus_test.id = 1;
    C_plus_plus_test.name = "Основы C++";
    Question C_plus_plus_q1;
    C_plus_plus_q1.text = "Какой оператор используется для вывода данных в C++?";
    C_plus_plus_q1.answers = {
        {"std::cin", false},
        {"std::cout", true},
        {"std::input", false},
        {"std::print", false}
    };
    Question C_plus_plus_q2;
    C_plus_plus_q2.text = "Какой тип данных используется для хранения целых чисел?";
    C_plus_plus_q2.answers = {
        {"double", false},
        {"char", false},
        {"int", true},
        {"bool", false}
    };
    C_plus_plus_test.questions.push_back(C_plus_plus_q1);
    C_plus_plus_test.questions.push_back(C_plus_plus_q2);
    C_plus_plus.tests.push_back(C_plus_plus_test);


    Category General_knowledges;
    General_knowledges.name = "Общие знания";
    Test General_knowledges_test;
    General_knowledges_test.id = 2;
    General_knowledges_test.name = "Простые вопросы";
    Question General_knowledges_q1;
    General_knowledges_q1.text = "Сколько планет в Солнечной системе?";
    General_knowledges_q1.answers = {
        {"7", false},
        {"8", true},
        {"9", false},
        {"10", false}
    };
    Question General_knowledges_q2;
    General_knowledges_q2.text = "Какой океан является самым большим?";
    General_knowledges_q2.answers = {
        {"Атлантический", false},
        {"Индийский", false},
        {"Тихий", true},
        {"Северный Ледовитый", false}
    };
    General_knowledges_test.questions.push_back(General_knowledges_q1);
    General_knowledges_test.questions.push_back(General_knowledges_q2);
    General_knowledges.tests.push_back(General_knowledges_test);
    tests.AddCategory(C_plus_plus);
    tests.AddCategory(General_knowledges);
}


void SystemLogic::GuestMenu(Guest& guest)
{
    int choice = 0;
    do
    {
        std::cout << "\n===== ГОСТЕВОЕ МЕНЮ =====\n";
        std::cout << "1. Начать тест\n";
        std::cout << "2. Предыдущие результаты\n";
        std::cout << "3. Вернуться в главное меню\n";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            StartGuestTesting(guest);
            break;

        case 2:
            tests.LookPrevious();
            break;

        case 3:
            break;

        default:
            std::cout << "Повторите выбор\n";
        }

    } while (choice != 3);
}

bool SystemLogic::IsLoginTaken(const std::string& login) const {
    for (const Guest& guest : All_Guests){
        if (guest.GetLogin() == login) {
            return true;
        }
    }
    return false;
}

void SystemLogic::StartGuestTesting(Guest& guest)
{
    const Category* category = tests.ChooseCategory();
    if (category == nullptr) {
        return;
    }
    const Test* selected_test = tests.ChooseTest(*category);
    if (selected_test == nullptr) {
        return;
    }
    TestAttempt attempt;
    attempt.StartTest(*selected_test);

    // Позже здесь сохраним результат гостя
}