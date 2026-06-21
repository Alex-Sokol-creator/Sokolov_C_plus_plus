#pragma once

struct Point {
	double x;
	double y;
};

void inputPoint(Point& p);
void printPoint(const Point& p);
double calculateDistance(const Point& p1, const Point& p2);
Point findMidpoint(const Point& p1, const Point& p2);