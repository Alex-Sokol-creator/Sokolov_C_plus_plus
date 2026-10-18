
#include <iostream>
#include <Windows.h>
#include <vector>
#include <array>
#include <list> // двусвязный список
#include <forward_list> // односвязный список
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*
    std::vector<int> arr{ 10,15,10 };

    arr.push_back(10);

    std::cout << arr[0] << '\n';
    std::cout << arr[1] << '\n';
    std::cout << arr[2] << '\n';

    std::cout << arr.size() << '\n';
    std::cout << arr.capacity() << '\n';

    arr.push_back(12);
    std::cout << arr.capacity() << '\n';

    arr.reserve(1000);
    std::cout << arr.capacity() << '\n';

    arr.insert(arr.begin() + 2, 98);

    for (int val : arr) {
        std::cout << val << '\n';
    }
    */

    /*
    const int SIZE = 2;
    int arr[SIZE] = { 10,12 };
    */

    std::array<int, 4> arr{ 10,12,14,5 };

    std::list<int> l{ 10,14,56,5,43 };
    // std::cout << l[1] << '\n';

    auto it = l.begin();
    std::advance(it, 3);

    l.insert(it, 49);

    for (int val : l) {
        std::cout << val << '\n';
    }

    // l.push_back();
    // l.push_front();
    // l.pop_back();

    std::map<std::string, int> grades;

    grades["Alex"] = 98;
    grades["Marie"] = 99;

    std::cout << grades["Alex"] << '\n';
    grades["Alex"] = 78;
    std::cout << grades["Alex"] << '\n';

    std::multimap<std::string, std::string> notes;
    notes.insert({ "work","fix bug№ 7435" });
    notes.insert({ "learning", "watch video about binary trees" });
    notes.insert({ "work", "send the report" });

    for (const auto &[category, task] : notes) {
        std::cout << category << ':' << task << '\n';
    }

    std::set<std::string> tags;

    tags.insert("C++");
    tags.insert("Python");
    tags.insert("html");
    tags.insert("C++");

    for (auto tag : tags) {
        std::cout << tag << '\n';
    }

    std::multiset<int> diceRolls;

    diceRolls.insert(3);
    diceRolls.insert(6);
    diceRolls.insert(1);
    diceRolls.insert(4);
    diceRolls.insert(4);
    diceRolls.insert(4);
    
    std::cout << diceRolls.count(4) << '\n';

    std::unordered_map<std::string, std::string> phoneBook;
    phoneBook["Alex"] = "+380504567867";

    std::stack<std::string> browserHistory;

    browserHistory.push("github.com");
    browserHistory.push("google.com");

    std::cout << browserHistory.top() << '\n';
    browserHistory.pop();
    std::cout << browserHistory.top() << '\n';

    std::queue<std::string> printQueue;

    printQueue.push("Document_1.pdf");
    printQueue.push("Picture.png");
    printQueue.push("Report.docx");

    while (!printQueue.empty()) {
        std::cout << "Printing: " << printQueue.front() << '\n';
        printQueue.pop();
    }
}

