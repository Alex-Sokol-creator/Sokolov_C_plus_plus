
#include <iostream>
#include <Windows.h>

using namespace std;

#define MinNum(num1, num2) do{ \
if ((num1) > (num2)) { \
    cout << (num2) << " is smaller than " << (num1); \
    } \
else if ((num1) < (num2)) { \
    cout << (num1) << " is smaller than " << (num2); \
} \
else { \
    cout << (num1) << " is equal to " << (num2); \
} \
}while(0)


#define MaxNum(num1, num2) do{ \
if ((num1) < (num2)) { \
    cout << (num2) << " is bigger than " << (num1); \
    } \
else if ((num1) > (num2)) { \
    cout << (num1) << " is bigger than " << (num2); \
} \
else { \
    cout << (num1) << " is equal to " << (num2); \
} \
}while(0)


#define SquarNum(num1) do{\
cout << (num1) * (num1);\
}while(0)


#define DegreeNum(num, degree) do{ \
double result = 1;\
if ((degree) >= 0){\
	for (int i = 0; i < (degree); i++) {\
			result *= (num);\
	}\
}\
else {\
	double divider = 1;\
	for (int i = (degree); i < 0; i++) {\
			divider *= (num);\
	}\
	result = 1 / divider;\
}\
cout << result;\
}while(0)


#define EvenNum(num) do{ \
if ((num) % 2 == 0){\
	cout << "Number " << (num) << " is even";\
}\
else {\
	cout << "Number " << (num) << " is not even";\
}\
}while(0)

#define OddNum(num) do{ \
if ((num) % 2 != 0) {\
	cout << "Number " << (num) << " is odd";\
}\
else {\
	cout << "Number " << (num) << " is not odd";\
}\
}while(0)

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\nMin Num: ";
	MinNum(12, 67);

	cout << "\nMax Num: ";
	MaxNum(12, 67);

	cout << "\nSquar Num: ";
	SquarNum(12);

	double num;
	int degree;
	cout << "\nEnter number, that you want to multiply in degree: ";
	cin >> num;
	cout << "Now enter degree: ";
	cin >> degree;
	cout << "\nNum " << num << " in degree " << degree << ": ";
	DegreeNum(num,degree);

	int number;
	cout << "\nEnter your num to check, odd it or no: ";
	cin >> number;
	OddNum(number);
	cout << "\nEnter your num to check, even it or no: ";
	cin >> number;
	EvenNum(number);
}

