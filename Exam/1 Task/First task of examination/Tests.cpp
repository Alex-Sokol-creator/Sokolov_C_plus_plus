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

void Tests::DeleteCategory(int index) {
	if (index < 0 || index >= categories.size()) {
		return;
	}
	categories.erase(categories.begin() + index);
}

const std::vector<Category>& Tests::GetCategories() const {
	return categories;
}

void Tests::AddTest(int category_index, const Test& test){
	if (category_index < 0 || category_index >= static_cast<int>(categories.size())) {
		return;
	}
	categories[category_index].tests.push_back(test);
}

void Tests::DeleteTest(int category_index, int test_index){
	if (category_index < 0 || category_index >= static_cast<int>(categories.size())) {
		return;
	}
	std::vector<Test>& selected_tests = categories[category_index].tests;
	if (test_index < 0 || test_index >= static_cast<int>(selected_tests.size())) {
		return;
	}
	selected_tests.erase(selected_tests.begin() + test_index);
}

void Tests::AddQuestion(int category_index, int test_index, const Question& question) {
	if (category_index < 0 || category_index >= categories.size()) {
		return;
	}
	if (test_index < 0 || test_index >= categories[category_index].tests.size()) {
		return;
	}
	categories[category_index].tests[test_index].questions.push_back(question);
}