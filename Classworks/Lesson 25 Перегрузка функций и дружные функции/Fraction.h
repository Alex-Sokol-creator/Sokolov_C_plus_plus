/*#pragma once
#include <iostream>

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int num, int denom);

	static Fraction add(const Fraction& f1, const Fraction& f2);

	Fraction operator+(const Fraction& other) const;

	Fraction operator+(int right) const;

	friend Fraction operator+(int left, const Fraction& right);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& obj);

	friend const std::istream& operator>>(const std::istream in, const Fraction& obj);

	// Префиксная форма
	Fraction& operator++();
	// Постфиксная форма
	Fraction& operator++(int);
};

*/


#pragma once
#include <iostream>

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int num, int denom);

	static Fraction add(const Fraction& f1, const Fraction& f2);

	Fraction operator+(const Fraction& right) const;
	Fraction operator+(int right) const;
	friend Fraction operator+(int left, const Fraction& right);

	Fraction operator-(const Fraction& right) const;
	Fraction operator-(int right) const;
	friend Fraction operator-(int left, const Fraction& right);

	Fraction operator*(const Fraction& right) const;
	Fraction operator*(int right)const;
	friend Fraction operator*(int left, const Fraction& right);

	Fraction operator/(const Fraction& right) const;
	Fraction operator/(int right) const;
	friend Fraction operator/(int left, const Fraction& right);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& obj);
	friend std::istream& operator>>(std::istream& in, Fraction& obj);

	// Префіксна форма
	Fraction& operator++();
	// Постфіксна форма
	Fraction operator++(int);

	Fraction& operator--();
	Fraction operator--(int);

	// Операторы сравнения
	bool operator==(const Fraction& right) const;
	std::strong_ordering operator<=>(const Fraction& right) const;

};

