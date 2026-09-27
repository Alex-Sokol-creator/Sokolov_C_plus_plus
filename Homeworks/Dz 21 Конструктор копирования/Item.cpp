#include "Item.h"
#include <iostream>

Item::Item(const MyString& item, ItemClass type) {
	this->item = item;
	this->type = type;
}

void Item::print() const {
	std::cout << "Item: " << item.c_str() << "\nType: ";
	switch (this->type) {
	case Weapon: { std::cout << "Weapon\n"; break; }
	case Potion: { std::cout << "Potion\n"; break; }
	case Food: { std::cout << "Food\n"; break; }
	case None: { std::cout << "None\n"; break; }
	}
}