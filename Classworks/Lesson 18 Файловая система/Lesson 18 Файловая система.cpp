
#include <iostream>
#include <Windows.h>
#include <io.h>

using namespace std;

typedef double MY_DOUBLE;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct _finddata_t info;
	char path[255];
	char mask[20]; // *.txt, test.*

	cout << "Enter path: ";
	cin >> path;
	cin.ignore();

	cout << "Enter mask: ";
	cin.getline(mask, 20);

	strcat_s(path, mask);

	auto handle = _findfirst(path, &info);
	if (handle == -1) {
		cout << "Files were not found\n";
	}
	else {
		do {
			cout << info.name << '\n';
		} while (_findnext(handle, &info) == 0);
		_findclose(handle);
	//

	// MY_DOUBLE var = 90.7;

	// atoi(); ASCII TO INT
	// itoa(); INT TO ASCII

	/*
	FILE* f;

	errno_t err = fopen_s(&f, "test.bin", "wb");

	if (err) {
		cout << "Unable to open file\n";
	}
	else {
		cout << "File is open, start writing...\n";
		char str[] = "some text that will be written to file";
		fwrite(&str, sizeof(char), strlen(str), f);
		cout << "Writing was successful!\n";
		fclose(f);
	}
	*/

	/*
	FILE* textFile;
	errno_t err = fopen_s(&textFile, "test.txt", "a");

	int i = 123;
	double d = 43.786;

	if (!err) {
		fprintf_s(textFile, "integer: %d\n", i);
		fprintf_s(textFile, "double: %.2f\n", d);

		fclose(textFile);
	}
	*/

	/*
	FILE* textFile;
	errno_t err = fopen_s(&textFile, "test.txt", "r");

	if (!err) {
		int i;
		double d;

		while (!feof(textFile)) {
			fscanf_s(textFile, "integer: %d\n", &i);
			fscanf_s(textFile, "double: %lf\n", &d);

			cout << i << ' ' << d << '\n';
		}
		fclose(textFile);
	}
	*/

	/*
	FILE* textFile;
	errno_t err = fopen_s(&textFile, "test.txt", "w");

	char textToWrite[] = "hello world";

	if (!err) {
		for (int i = 0; i < strlen(textToWrite); i++) {
			fputc(textToWrite[i], textFile);
		}
		fclose(textFile);
	}
	*/

	/*
	FILE* textFile;
	errno_t err = fopen_s(&textFile, "test.txt", "r");

	if (!err) {
		while (!feof(textFile)) {
			cout << (char)fgetc(textFile);
		}
		fclose(textFile);
	}
	*/

	/*
	FILE* textFile;
	errno_t err = fopen_s(&textFile, "test.bin", "r");

	if (!err) {
		char ch = fgetc(textFile);
		cout << ch << '\n';

		fpos_t pos;
		fgetpos(textFile, &pos);
		cout << pos << '\n';

		fseek(textFile, -1, SEEK_END);

		ch = fgetc(textFile);
		cout << ch << '\n';

		fclose(textFile);
	}
	*/

	
}
