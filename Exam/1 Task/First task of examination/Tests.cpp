#include "Tests.h"
#include <iostream>

const Category* Tests::ChooseCategory() const {
	int choice = 0;
	while (choice <= 0 || choice > categories.size()) {
		std::cout << "Выберите категорию тестов от 1 до " << categories.size() << ": ";
		std::cin >> choice;
	}
	return &categories[choice - 1];
}

const Test* Tests::ChooseTest(const Category& category) const {
	if (category.tests.empty()) {
		std::cout << "К сожалению, в этой категории пока что нет тестов\n";
		return nullptr;
	}
	int choice = 0;
	std::cout << "Тесты по категории: " << category.name << '\n';
	for (int i = 0; i < category.tests.size(); i++) {
		std::cout << i + 1 << ": " << category.tests[i].name << '\n';
	}
	while (choice <= 0 || choice > category.tests.size()) {
		std::cout << "Выберите тест от 1 до " << category.tests.size() << ": ";
		std::cin >> choice;
	}
	return &category.tests[choice - 1];
}

void Tests::AddCategory(const Category& category){
	categories.push_back(category);
}