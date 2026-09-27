#pragma once
#include "MyString.h"

enum ItemClass {
	Weapon, Potion, Food, None
};

class Item
{
private:
	MyString item;
	ItemClass type;
public:
	Item() : item(), type(None) {};

	Item(const MyString& item, ItemClass type);

	void print() const;
};

