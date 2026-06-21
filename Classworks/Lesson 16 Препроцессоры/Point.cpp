#include "Point.h"
#include <iostream>
#include <cmath>

void inputPoint(Point& p) {
	std::cout << "Enter X coordinates: ";
	std::cin >> p.x;
	std::cout << "Enter Y coordinates: ";
	std::cin >> p.y;
}

void printPoint(const Point& p) {
	std::cout << "(" << p.x << ", " << p.y << ")";
}

double calculateDistance(const Point& p1, const Point& p2) {
	return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

Point findMidpoint(const Point& p1, const Point& p2) {
	return {
		(p1.x + p2.x) / 2,
		(p1.y + p2.y) / 2
	};
}