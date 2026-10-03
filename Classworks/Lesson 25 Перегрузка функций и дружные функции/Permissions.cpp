#include "Permissions.h"
#include <iostream>

Permissions operator|(const Permissions& p1, const Permissions& p2) {
	// 000000001 | 000000010 = 000000011
	return Permissions(p1.mask | p2.mask);
}

Permissions operator&(const Permissions& p1, const Permissions& p2) {
	return Permissions(p1.mask & p2.mask);
}

void Permissions::print() const {
	std::cout << "Mask: " << mask << '\n';
}

bool Permissions::operator!() const {
	return mask == None;
}