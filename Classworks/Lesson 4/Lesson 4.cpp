

#include <iostream>
#include <Windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //int num;
    //cout << num << '\n';
    const int size = 5;

    int numbers[size] = {10,12,13,15,16};
    //char symbols[] = {'j','h','i'};
    //bool booleans[6];

    //numbers[0] = 10;

    //symbols[2] = 'k';

    //cout << numbers[0] << '\n';
    //cout << symbols[2] << '\n';

    //cout << numbers << '\n';
    //cout << booleans << '\n';

    //cout << numbers[6] << '\n';
    cout << numbers[4] << '\n';

    cout << sizeof(size) << '\n';
    cout << sizeof(numbers) << '\n';

    //int counter = 0;
    //while (counter < size) {
    //    numbers[counter] = counter;
    //    counter++;
    //}
    //cout << numbers[counter-1] << '\n';

    //for (int i = 0; i < size; i++) {
    //    numbers[i] = i;
    //}

    //for (int i = 0; i < size; i++) {
    //    cout << numbers[i] << ' ';
    //}
    cout << '\n';

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    cout << "Sum: " << sum << '\n';

    for (int num : numbers) {
        cout << num << ' ';
        num = 10;
    }

    auto symbol = 'k';
}

