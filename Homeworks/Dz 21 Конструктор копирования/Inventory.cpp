#include "Inventory.h"
#include <iostream>

Inventory::Inventory(int size) {
	this->items = new Item[size];
	this->size = size;
}

Inventory::Inventory(const Inventory& other) {
	this->size = other.size;
	this->items = new Item[size];
	for (int i = 0; i < size; i++) {
		this->items[i] = other.items[i];
	}
}

Inventory::~Inventory() {
	delete[] items;
}

void Inventory::setItem(int index, const Item& item) {
	if (index < 0 || index >= size) {
		std::cout << "Данный индекс недоступен\n";
		return;
	}
	this->items[index] = item;
}

void Inventory::print() const {
	std::cout << "Вот все предметы: \n";
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << " предмет:\n";
		items[i].print();
	}
}