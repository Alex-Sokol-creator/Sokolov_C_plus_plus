#include "SystemLogic.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>


// Базовые категории, тесты, вопросы и ответы
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

    files.LoadTests(tests);
}


// Запуск программы

void SystemLogic::Run()
{
    int choice = 0;
    do {
        std::cout << "\n========== Система тестирования ==========\n";
        std::cout << "1. Регистрация гостя\n";
        std::cout << "2. Вход гостя\n";
        std::cout << "3. Регистрация администратора\n";
        std::cout << "4. Вход администратора\n";
        std::cout << "5. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
        case 1:{
            GuestsRegistration();
            break;
        }
        case 2:{
            Entering_the_system_guests();
            break;
        }
        case 3: {
            AdminRegistration();
            break;
        }
        case 4:{
            Entering_the_system_admin();
            break;
        }
        case 5: {
            files.SaveTests(tests);
            std::cout << "Завершение программы...\n";
            break;
        }
        default:
            std::cout << "Неверный выбор!\n";
            break;
        }
    } while (choice != 5);
}


// Контроль гостя

void SystemLogic::GuestsRegistration()
{
    PIB personal_data;
    std::string personal_address;
    std::string phone_number;
    std::string login;
    std::string password;
    std::cout << "\n===== РЕГИСТРАЦИЯ ГОСТЯ =====\n";
    std::cout << "Введите имя: ";
    std::cin >> personal_data.name;
    std::cout << "Введите фамилию: ";
    std::cin >> personal_data.surname;
    std::cout << "Введите отчество: ";
    std::cin >> personal_data.fathers_name;
    std::cin.ignore();
    std::cout << "Введите адрес: ";
    std::getline(std::cin, personal_address);
    std::cout << "Введите номер телефона: ";
    std::getline(std::cin, phone_number);
    std::cout << "Придумайте логин: ";
    std::getline(std::cin, login);
    if (IsLoginTaken(login)) {
        std::cout << "Такой логин уже существует!\n";
        return;
    }
    std::cout << "Придумайте пароль: ";
    std::getline(std::cin, password);
    Guest new_guest(personal_data, personal_address, phone_number, login, password);
    if (new_guest.CheckGuestData() != true) {
        std::cout << "Ошибка! Заполните все обязательные данные.\n";
        return;
    }
    All_Guests.push_back(new_guest);
    std::cout << "\nРегистрация успешно завершена!\n";
}


void SystemLogic::Entering_the_system_guests() {
    std::string login_entered;
    std::string password_entered;
    std::cout << "Введите логин для входа в систему: ";
    std::getline(std::cin, login_entered);
    bool founded = false;
    int guest_index = 0;
    for (const Guest& guest : All_Guests) {
        if (guest.GetLogin() == login_entered) {
            founded = true;
            break;
        }
        guest_index++;
    }
    if (founded == true) {
        std::cout << "Введите пароль для входа в систему: ";
        std::getline(std::cin, password_entered);
        if (All_Guests[guest_index].CheckPassword(password_entered)) {
            std::cout << "Авторизация произошла успешно\n";
            GuestMenu(All_Guests[guest_index]);
        }
        else {
            std::cout << "Пароль неверный, повторите попытку авторизации\n";
            return;
        }
    }
    else {
        std::cout << "К сожалению такого логина нет в нашей базе данных, повторите попытку или же зарегистрируйтесь\n";
        return;
    }
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
            guest.ShowResults();
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

    if (attempt.IsFinished()) {
        TestResult result{
            selected_test->id,
            selected_test->name,
            attempt.GetCorrectAnswers(),
            attempt.GetRightPercentage(),
            attempt.GetResultGrade() };
    guest.AddResult(result);
    std::cout << "\nРезультат успешно добавлен в вашу историю!\n";
    }
    else {
        std::cout << "\nРезультат не сохранён, поскольку тест не был завершён.\n";
    }

    // Позже здесь сохраним результат гостя
}


// Админ

void SystemLogic::AdminRegistration(){
    if (admin_registered) {
        std::cout << "Администратор уже зарегистрирован!\n";
        return;
    }
    PIB personal_data;
    std::string personal_address;
    std::string phone_number;
    std::string login;
    std::string password;
    std::cout << "\n===== РЕГИСТРАЦИЯ АДМИНИСТРАТОРА =====\n";
    std::cout << "Введите имя: ";
    std::getline(std::cin, personal_data.name);
    std::cout << "Введите фамилию: ";
    std::getline(std::cin, personal_data.surname);
    std::cout << "Введите отчество: ";
    std::getline(std::cin, personal_data.fathers_name);
    std::cout << "Введите адрес: ";
    std::getline(std::cin, personal_address);
    std::cout << "Введите номер телефона: ";
    std::getline(std::cin, phone_number);
    std::cout << "Придумайте логин: ";
    std::getline(std::cin, login);
    std::cout << "Придумайте пароль: ";
    std::getline(std::cin, password);
    if (personal_data.name.empty() ||
        personal_data.surname.empty() ||
        personal_address.empty() ||
        phone_number.empty() ||
        login.empty() ||
        password.empty()) {
        std::cout << "Ошибка! Заполните обязательные поля.\n";
        return;
    }
    admin = Admin(personal_data, personal_address, phone_number, login, password);
    admin_registered = true;
    std::cout << "\nАдминистратор успешно зарегистрирован!\n";
}


void SystemLogic::Entering_the_system_admin(){
    if (!admin_registered) {
        std::cout << "Администратор ещё не зарегистрирован!\nСначала зарегистрируйте администратора.\n";
        return;
    }
    std::string login_entered;
    std::string password_entered;
    std::cout << "\n===== ВХОД АДМИНИСТРАТОРА =====\n";
    std::cout << "Введите логин: ";
    std::getline(std::cin, login_entered);
    if (admin.GetLogin() != login_entered) {
        std::cout << "Неверный логин, повторите попытку\n";
        return;
    }
    std::cout << "Введите пароль: ";
    std::getline(std::cin, password_entered);
    if (admin.CheckPassword(password_entered)) {
        std::cout << "\nАвторизация успешна!\n";
        AdminMenu();
    }
    else {
        std::cout << "Неверный пароль, повторите попытку\n";
    }
}


void SystemLogic::AdminMenu(){
    int choice = 0;
    do {
        std::cout << "\n========== МЕНЮ АДМИНИСТРАТОРА ==========\n";
        std::cout << "1. Просмотреть гостей\n";
        std::cout << "2. Добавить гостя\n";
        std::cout << "3. Удалить гостя\n";
        std::cout << "4. Изменить данные гостя\n";
        std::cout << "5. Управление категориями\n";
        std::cout << "6. Управление тестами\n";
        std::cout << "7. Статистика\n";
        std::cout << "8. Изменить логин администратора\n";
        std::cout << "9. Изменить пароль администратора\n";
        std::cout << "10. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            admin.GetTools().ShowGuests(All_Guests);
            break;
        case 2:
            admin.GetTools().AddGuest(All_Guests);
            break;
        case 3:
            admin.GetTools().DeleteGuest(All_Guests);
            break;
        case 4:
            admin.GetTools().ModifyGuest(All_Guests);
            break;
        case 5:
            admin.GetTools().ManageCategories(tests);
            break;
        case 6:
            admin.GetTools().ManageTests(tests);
            break;
        case 7:
            admin.GetTools().ShowStatistics(tests);
            break;
        case 8:
            std::cin.ignore();
            admin.ChangeLogin();
            break;
        case 9:
            std::cin.ignore();
            admin.ChangePassword();
            break;
        case 10:
            std::cout << "Выход из административного меню...\n";
            break;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != 10);
}


// Сохранение и загрузка

void Files::SaveTests(const Tests& tests) {
    std::ofstream file("tests.txt");
    if (file.is_open() != true) {
        std::cout << "Не удалось открыть файл для сохранения!\n";
        return;
    }
    const auto& categories = tests.GetCategories();
    file << categories.size() << '\n';
    for (const Category& category : categories) {
        file << std::quoted(category.name) << '\n';
        file << category.tests.size() << '\n';
        for (const Test& test : category.tests) {
            file << test.id << '\n';
            file << std::quoted(test.name) << '\n';
            file << test.questions.size() << '\n';
            for (const Question& question : test.questions) {
                file << std::quoted(question.text) << '\n';
                file << question.answers.size() << '\n';
                for (const Answer& answer : question.answers) {
                    file << std::quoted(answer.text) << ' '
                        << answer.is_correct << '\n';
                }
            }
        }
    }
    std::cout << "Тесты успешно сохранены в файл!\n";
}

void Files::LoadTests(Tests& tests) {
    std::ifstream file("tests.txt");
    if (file.is_open() != true) {
        std::cout << "Файл с тестами не найден. Используются стандартные тесты.\n";
        return;
    }
    std::vector<Category> loaded_categories;
    int category_count;
    if (!(file >> category_count) || category_count < 0) {
        std::cout << "Ошибка формата файла!\n";
        return;
    }

    for (int i = 0; i < category_count; i++) {
        Category category;
        int test_count;
        if (!(file >> std::quoted(category.name) >> test_count) ||
            test_count < 0) {
            std::cout << "Ошибка загрузки категорий!\n";
            return;
        }
        for (int j = 0; j < test_count; j++) {
            Test test;
            int question_count;
            if (!(file >> test.id >> std::quoted(test.name) >> question_count) || question_count < 0) {
                std::cout << "Ошибка загрузки тестов!\n";
                return;
            }
            for (int k = 0; k < question_count; k++) {
                Question question;
                int answer_count;
                if (!(file >> std::quoted(question.text) >> answer_count) || answer_count < 0) {
                    std::cout << "Ошибка загрузки вопросов!\n";
                    return;
                }
                for (int a = 0; a < answer_count; a++) {
                    Answer answer;
                    if (!(file >> std::quoted(answer.text) >> answer.is_correct)) {
                        std::cout << "Ошибка загрузки ответов!\n";
                        return;
                    }
                    question.answers.push_back(answer);
                }
                test.questions.push_back(question);
            }
            category.tests.push_back(test);
        }
        loaded_categories.push_back(category);
    }
    tests.SetCategories(loaded_categories);
    std::cout << "Тесты успешно загружены из файла!\n";
}