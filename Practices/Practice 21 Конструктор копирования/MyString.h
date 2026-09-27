#pragma once

class MyString {
private:
	char* mystring;
	int length;
public:
	MyString();
	MyString(const char* string_entered);
	MyString(const MyString& other);

	~MyString();

	int GetMyStringLength() const;
	const char* c_str() const;
};