#pragma once

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
};