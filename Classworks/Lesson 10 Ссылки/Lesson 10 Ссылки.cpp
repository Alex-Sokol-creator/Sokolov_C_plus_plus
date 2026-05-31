
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
void SwapValues(T& val1, T& val2) {
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

void PrintArr(const int* arr, const int& size) {
    for (int i = 0; i < size; i++) {
        // arr[i] = 12;
        // size = 123
        cout << arr[i] << '\n';
    }
}

int& badFunction() {
    int number = 10;
    return number;
}

int& rmax(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        maxIndex = (arr[maxIndex] > arr[i]) ? maxIndex : i;
    }
    return arr[maxIndex];
}

int* AddGrade(int* grades, int& size, int newGrade) {
    int* temp = new int[size + 1];
    for (int i = 0; i < size;i++) {
        temp[i] = grades[i];
    }
    temp[size] = newGrade;
    size++;
    delete[] grades;
    grades = temp;
    return grades;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int gradesCount;

    cout << "Enter grades count: ";
    cin >> gradesCount;

    int* grades = new int[gradesCount];
    for (int i = 0; i < gradesCount; i++) {
        cout << "Enter grade: " << i + 1 << ": ";
        cin >> grades[i];
    }
    PrintArr(grades, gradesCount);

    int newGrade;
    cout << "Enter new grade: ";
    cin >> newGrade;
    grades = AddGrade(grades, gradesCount, newGrade);
    PrintArr(grades, gradesCount);

    delete[] grades;

    /*
    float* ptrF = new float(2.5);
    cout << ptrF << '\n';
    cout << *ptrF << '\n';

    delete ptrF;
    */

    /*
    int arr[] = { 10,12,56,4 };
    int& arrMax = rmax(arr, 4);
    PrintArr(arr, 4);
    cout << "---------\n";
    cout << arrMax << '\n';
    cout << "---------\n";
    arrMax = -40;
    PrintArr(arr, 4);
    cout << "---------\n";

    int& num = badFunction();
    cout << num << '\n';
    */

    /*
    int var = 1234;
    int* ptr = &var;
    int& ref = var;
    cout << "Var: " << var << '\n';
    cout << "Ptr: " << *ptr << '\n';
    cout << "Ref: " << ref << '\n';

    cout << "Adress var: " << &var << '\n';
    cout << "Adress int ptr: " << ptr << '\n';
    cout << "Adress OF ptr: " << &ptr << '\n';
    cout << "Adress ref: " << &ref << '\n';

    cout << var << '\n';
    ref = 14;
    cout << var << '\n';

    int var2 = 9876;
    ref = var2;

    cout << var << '\n';
    
    int a = 10, b = 12;
    cout << "a: " << a << " --- b: " << b << '\n';
    SwapValues(a, b);
    cout << "a: " << a << " --- b: " << b << '\n';

    int number = 12345;
    const int& refnum = number;
    // ref = 2345; // константная ссылка - нельзя менять значение!
    number = 132;

    const double PI = 3.14;
    const double& refpi = PI;

    // ref = 12.5;

    int arr[] = { 10,4,56,4 };
    PrintArr(arr, 4);
    */
}

