#pragma once
#include "Item.h"
class Inventory
{
private:
	int size;
	Item* items;
public:
	Inventory(int size);

	Inventory(const Inventory& other);

	~Inventory();

	void setItem(int index, const Item& item);

	void print() const;
};

