
#include <iostream>
#include <Windows.h>;

using namespace std;

//Функция, которая получает рядок и возвращает количество символов в предложении
int myStrlenth(const char* arr) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //string myStr = "hello, world!"; // ЗАПРЕЩЕНО ИСПОЛЬЗОВАТЬ!!!
    //cout << myStr << '\n';

    /*
    char myStr[] = "hello, world!"; // string (предложения) в стиле С
    cout << myStr << '\n';

    char myStr2[5]; //TTTTT
    for (int i = 0; i < 4; i++) {
        myStr2[i] = 'T';
    }
    myStr2[4] = '\0'; // ноль-терминатор
    cout << myStr2 << '\n';
    */

    /*

    cout << (int)'H' << '\n';
    cout << (int)'9' << '\n';
    cout << (int)'#' << '\n';

    cout << (int)'A' << ' ' << (int)'a' << '\n';
    cout << ('A' > 'a') << '\n';

    cout << (char)165 << '\n';
    */

    /*
    char32_t emoji = U'😎';
    cout << emoji << '\n';
    */

    /*

    char myStr[] = "hello, world!";

    char* ptr = myStr;
    // myStr = "goodbye";

    myStr[4] = 'u';
    cout << myStr << '\n';

    cout << "myStr length: " << myStrlenth("qwerty12345") << '\n';
    cout << "myStr length: " << strlen("qwerty12345") << '\n';

    char str1[] = "Hello, ", str2[] = "world!";
    const int size = strlen(str1) + strlen(str2) + 1;
    char* result = new char[strlen(str1) + strlen(str2) + 1]; // Hello, world!\0

    strcpy_s(result, size, str1); // strcmp - копирует
    strcat_s(result, size, str2); // strcat - ставит ноль-терминатор в конец
    cout << result << '\n';
    delete[] result;
    */

    char str1[] = "apple";
    char str2[] = "Apple2";

    int result = strcmp(str1, str2); // strcmp - сравнивает рядки

    cout << result << '\n';

    if (result >= 1) {
        cout << "str1 is bigger than str2\n";
    }
    else if (result == 0) {
        cout << "str1 is equal to str2\n";
    }
    else {
        cout << "str1 is smaller than str2\n";
    }

    printf(str1);
    printf("\nresult: %i", result);
    printf("fraction: %.2f", 12.567788);

    char fullName[255];
    //cout << "\nEnter your name: ";
    //cin >> fullName;
    //cout << fullName << '\n';

    scanf_s("%s", fullName, 255);
    printf("Name: %s\n", fullName);

    int age;
    scanf_s("%d", &age);
    printf("Age: %d\n", age);

    fgets(fullName, 255, stdin);
    cout << fullName << '\n';
};

