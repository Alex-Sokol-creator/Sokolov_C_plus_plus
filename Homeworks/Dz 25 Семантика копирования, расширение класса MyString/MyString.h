#pragma once
#include <iostream>

class MyString {
private:
	char* data;
	size_t length;
public:
	MyString();
	MyString(const char* string_entered);
	MyString(const MyString& other);

	~MyString();

	size_t GetMyStringLength() const;
	const char* c_str() const;

	MyString& operator=(const MyString& other);

	char& operator[](size_t index);

	const char& operator[](size_t index) const;


	MyString(MyString&&) noexcept;

	MyString& operator=(MyString&&) noexcept;

	friend MyString operator+(const MyString& num1, const MyString& num2);

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};