
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
		errno_t err2 = fopen_s(&secondfile, "secondfile.txt", "w");
		if (err1 || err2) {
			cout << "При попытке открыть файлы произошла ошибка\n";
		}
		else {
			char word[100];
			while (fscanf_s(firstfile, "%s", word, sizeof(word)) == 1) {
				if (strlen(word) >= 7) {
					fprintf_s(secondfile, "%s ", word);
				}
			}
			cout << "Task was succesfully completed";
		}
		fclose(firstfile);
		fclose(secondfile);
	}

	{
		cout << "\nSecond Task\n";
		FILE* firstfile;
		FILE* firstfile_idealcopy;
		errno_t err1 = fopen_s(&firstfile, "firstfile.txt", "r");
		errno_t err2 = fopen_s(&firstfile_idealcopy, "firstfile_idealcopy.txt", "w");
		if (err1 || err2) {
			cout << "При попытке открыть файлы произошла ошибка\n";
		}
		else {
			char symbol;
			while ((symbol = fgetc(firstfile)) != EOF) {
				fputc(symbol, firstfile_idealcopy);
			}
			cout << "Task was succesfully completed";
		}
		fclose(firstfile);
		fclose(firstfile_idealcopy);
	}

	{
		cout << "\nThird Task\n";
		FILE* firstfile;
		FILE* firstfile_reverse;
		errno_t err1 = fopen_s(&firstfile, "firstfile.txt", "r");
		errno_t err2 = fopen_s(&firstfile_reverse, "firstfile_reverse.txt", "w");
		if (err1 || err2) {
			cout << "При попытке открыть файлы произошла ошибка\n";
		}
		else {
			char symbol, text[5000];
			int pos = -1, pos_read = 0;
			int length = 0;
			//fseek(firstfile, pos, SEEK_END);
			while ((symbol = fgetc(firstfile)) != EOF) {
				text[length] = symbol;
				length++;
				//pos--;
				//fseek(firstfile, pos, SEEK_END);
			}
			int end = length;
			for (int i = length - 1; i >= 0; i--) {
				if (text[i] == '\n' || i == 0) {
					if (i == 0) {
						pos_read = i;
					}
					else {
						pos_read = i + 1;
					}
					int movingstroka = pos_read;
					for (int start = pos_read; start < end; start++) {
						fprintf_s(firstfile_reverse, "%c", text[start]);
						movingstroka++;
					}
					fprintf_s(firstfile_reverse, "\n", text[movingstroka]);
					end = i;
				}
			}
			/*
			while ((symbol = fgetc(firstfile)) != EOF) {
				fputc(symbol, firstfile_reverse);
				pos--;
				fseek(firstfile, pos, SEEK_END);
			}
			*/
			cout << "Task was succesfully completed";
		}
		fclose(firstfile);
		fclose(firstfile_reverse);
	}

	{
		cout << "\nFourth Task\n";
		FILE* firstfile;
		FILE* firstfile_withriski;
		errno_t err1 = fopen_s(&firstfile, "firstfile.txt", "r");
		errno_t err2 = fopen_s(&firstfile_withriski, "firstfile_withriski.txt", "w");
		if (err1 || err2) {
			cout << "При попытке открыть файлы произошла ошибка\n";
		}
		else {
			char symbol, text[5000], textcheck[5000];
			int resultstroka = -1, length = 0, lengthcheck = 0, currentstroka = 1;
			while ((symbol = fgetc(firstfile)) != EOF) {
				text[length] = symbol;
				length++;
			}
			for (int i = 0; i < length; i++) {
				textcheck[lengthcheck] = text[i];
				if (textcheck[lengthcheck] == '\n') {
					int continue_or_not = 1;
					for (int check = 0; check < lengthcheck; check++) {
						if (textcheck[check] == ' ') {
							continue_or_not = -1;
							break;
						}
					}
					if (continue_or_not == 1) {
						resultstroka = currentstroka;
						currentstroka++;
					}
					else {
						currentstroka++;
					}
					memset(textcheck, 0, sizeof(textcheck));
					lengthcheck = 0;
				}
				lengthcheck++;
			}
			currentstroka = 1;
			for (int i = 0; i < length; i++) {
				fputc(text[i], firstfile_withriski);
				if (text[i] == '\n') {
					if (currentstroka == resultstroka) {
						char riski[] = "------------";
						fprintf_s(firstfile_withriski, "%s\n", riski);
					}
					currentstroka++;
				}
			}
			if (resultstroka == -1) {
				char riski[] = "------------";
				fprintf_s(firstfile_withriski, "%s\n", riski);
			}
			cout << "Task was succesfully completed";
		}
		fclose(firstfile);
		fclose(firstfile_withriski);
	}
}
