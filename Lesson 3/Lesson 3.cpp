

#include <iostream>

using namespace std;

int main()
{
    /*std::cout << "Hello World!\n";
    std::cout << "Polina Lox\n";*/

    /*int counter = 0;
    int times;

    cin >> times;*/

    /*while (counter < times) {
        std::cout << counter << ' ';
        counter++;
    }*/

    /*do {
        cout << counter << ' ';
        counter++;
    } while (counter < times);*/

    /*int i = 0;*/

    /*for (int i = 0; i < 10; i++) {
        cout << i << ' ';
    }*/

    /*double num1, num2;
    char action;
    char answer;

    while (true) {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose operation(+, -, *, / ): ";
        cin >> action;

        switch (action) {
        case '+': cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n'; break;
        case '-': cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n'; break;
        case '*': cout << num1 << " * " << num2 << " = " << num1 * num2 << '\n'; break;
        case '/': cout << num1 << " / " << num2 << " = " << num1 / num2 << '\n'; break;
        default: cout << "Incorrect operation\n";
        }

        cout << "Do you want to continue? (y/n)\n>";
        cin >> answer;
        if (answer == 'n') break;
    }
    cout << "Ok, bye!";*/

    /*for (int i = 0; i < 100; i++) {
        if (i % 4 == 0) continue;
        cout << i << ' ';
    }*/

    /*for (int i = 0; i < 10; i++) {
        cout << i << " Iteration" << ": ";
        for (int j = 0; j < 5; j++) {
            cout << j << ' ';
        }
        cout << '\n';
    }*/

    int width;
    int height;
    char symbol;

    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter symbol: ";
    cin >> symbol;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << symbol;
        }
        cout << '\n';
    }
}
