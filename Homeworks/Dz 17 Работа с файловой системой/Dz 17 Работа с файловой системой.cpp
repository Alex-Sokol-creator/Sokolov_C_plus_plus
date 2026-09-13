
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
		cout << "\nFirst Task\n";
		FILE* firstfile;
		FILE* secondfile;
		errno_t err1 = fopen_s(&firstfile, "firstfile.txt", "r");
		errno_t err2 = fopen_s(&secondfile, "secondfile.txt", "r");
		if (err1 || err2) {
			cout << "К сожалению, при попытке открыть файлы произошла ошибка\n";
		}
		else {
			char stroka1[5000], stroka2[5000], different1[5000], different2[5000];
			int count_of_1 = 1, count_of_2 = 1, check = 0;
			cout << "Вот строки, которые не идентичны друг другу:\n";
			/*
			while (fgets(stroka1, sizeof(stroka1), firstfile) != NULL && fgets(stroka2, sizeof(stroka2), secondfile) != NULL) {
				//int length1, length2;
				//length1 = strlen(stroka1), length2 = strlen(stroka2);
				if (strcmp(stroka1, stroka2) != 0) {
					check = 1;
					if (stroka1 != NULL) {
						cout << count_of_1 << " строка из первого файла: " << stroka1 << '\n';
						count_of_1++;
					}
					if (stroka2 != NULL) {
						cout << count_of_2 << " строка из второго файла: " << stroka2 << '\n';
						count_of_2++;
					}
				}
			}
			*/
			while (true) {
				char* result1 = NULL;
				char* result2 = NULL;
				result1 = fgets(stroka1, sizeof(stroka1), firstfile);
				result2 = fgets(stroka2, sizeof(stroka2), secondfile);
				if (result1 == NULL && result2 == NULL) {
					break;
				}
				if (result1 != NULL && result2 != NULL) {
					if (strcmp(stroka1, stroka2) != 0) {
						check = 1;
						cout << count_of_1 << " строка из первого файла: " << stroka1 << '\n';
						cout << count_of_2 << " строка из второго файла: " << stroka2 << '\n';
					}
					count_of_1++;
					count_of_2++;
				}
				else if (result1 == NULL && result2 != NULL) {
					check = 1;
					cout << "Первый файл завершился\n";
					cout << count_of_2 << " строка из второго файла: " << stroka2 << '\n';
					count_of_2++;
				}
				else {
					check = 1;
					cout << count_of_1 << " строка из первого файла: " << stroka1 << '\n';
					count_of_1++;
					cout << "Второй файл завершился\n";
				}
			}
			if (check == 0) {
				cout << "Таких строк нет, оба файла идентичны\n";
			}
			fclose(firstfile);
			fclose(secondfile);
		}
	}

	{
		cout << "\nSecond Task\n";
		FILE* file_for_statistic;
		FILE* statistic_file;
		errno_t err1 = fopen_s(&file_for_statistic, "file_for_statistic.txt", "r");
		errno_t err2 = fopen_s(&statistic_file, "statistic_file.txt", "w");
		if (err1 || err2) {
			cout << "К сожалению, при попытке открыть файлы произошла ошибка\n";
		}
		else {

		}
	}
}

