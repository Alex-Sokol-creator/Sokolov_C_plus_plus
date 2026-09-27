
#include "MyString.h"
#include <iostream>

using namespace std;

MyString::MyString() : mystring(nullptr), length(0) {};

MyString::MyString(const char* string_entered) {
	int stringSize = strlen(string_entered) + 1;
	length = strlen(string_entered);
	this->mystring = new char[stringSize];
	strcpy_s(this->mystring, stringSize, string_entered);
}

MyString::MyString(const MyString& other) {
	if (other.mystring != nullptr) {
		int stringSize = strlen(other.mystring) + 1;
		length = strlen(other.mystring);
		this->mystring = new char[stringSize];
		for (int i = 0; i < stringSize; i++) {
			this->mystring[i] = other.mystring[i];
		}
	}
	else {
		this->mystring = nullptr;
		length = 0;
	}
}

MyString::~MyString() {
	if (mystring != nullptr) {
		delete[] mystring;
	}
}

int MyString::GetMyStringLength() const{
	return length;
}

const char* MyString::c_str() const {
	return mystring;
}