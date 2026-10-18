
#include "MyString.h"
#include <iostream>

using namespace std;

MyString::MyString() : length(0) {
	this->data = new char[1];
	this->data[0] = '\0';
};

MyString::MyString(const char* string_entered) {
	int stringSize = strlen(string_entered) + 1;
	length = strlen(string_entered);
	this->data = new char[stringSize];
	strcpy_s(this->data, stringSize, string_entered);
}

MyString::MyString(const MyString& other) {
	if (other.data != nullptr) {
		int stringSize = strlen(other.data) + 1;
		length = strlen(other.data);
		this->data = new char[stringSize];
		for (int i = 0; i < stringSize; i++) {
			this->data[i] = other.data[i];
		}
	}
	else {
		this->data = nullptr;
		length = 0;
	}
}

MyString::~MyString() {
	if (data != nullptr) {
		delete[] data;
	}
}

size_t MyString::GetMyStringLength() const {
	return length;
}

const char* MyString::c_str() const {
	return data;
}


MyString& MyString::operator=(const MyString& other) {
	if (this == &other) {
		return *this;
	}

	if (this->data != nullptr) {
		delete[] this->data;
	}

	if (other.data != nullptr) {
		int stringSize = strlen(other.data) + 1;
		this->length = other.length;
		this->data = new char[stringSize];
		for (int i = 0; i < stringSize; i++) {
			this->data[i] = other.data[i];
		}
	}
	else {
		this->data = nullptr;
		this->length = 0;
	}

	return *this;
}


char& MyString::operator[](size_t index) {
	if (index >= length) {
		throw std::out_of_range("Выход за границы массива\n");
	}
	return data[index];
}

const char& MyString::operator[](size_t index) const {
	if (index >= length) {
		throw std::out_of_range("Выход за границы массива\n");
	}
	return data[index];
}