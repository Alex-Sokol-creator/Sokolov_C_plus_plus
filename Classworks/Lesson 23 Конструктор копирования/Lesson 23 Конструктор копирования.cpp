
#include <iostream>
#include <Windows.h>

using namespace std;

class Book {
private:
    char* title = nullptr;
    char* author = nullptr;
    int pages = 0;
public:
    Book(const char* title, const char* author, int pages)
    : pages(pages){
        int titleSize = strlen(title) + 1;
        int authorSize = strlen(author) + 1;

        this->title = new char[titleSize];
        strcpy_s(this->title, titleSize, title);

        this->author = new char[authorSize];
        strcpy_s(this->author, authorSize, author);
    }

    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy_s(title, strlen(other.title) + 1, other.title);
        author = new char[strlen(other.author) + 1];
        strcpy_s(author, strlen(other.author) + 1, other.author);
        this->pages = other.pages;
    }

    ~Book() {
        if (title != nullptr) {
            delete[] title;
        }
        if (author != nullptr) {
            delete[] author;
        }
    }

    void SetTitle(const char* title) {
        if (title != nullptr) {
            delete[] title;
        }
        this->title = new char[strlen(title) + 1];
        strcpy_s(this->title, strlen(title) + 1, title);
    }

    void SetAuthor(const char* author) {
        if (author != nullptr) {
            delete[] author;
        }
        this->author = new char[strlen(author) + 1];
        strcpy_s(this->author, strlen(author) + 1, author);
    }

    void SetPages(int pages) {
        this->pages = pages;
    }

    const char* GetTitle() const{ return title; }
    const char* GetAuthor() const{ return author; }
    int GetPages() const { return pages; }

};

void PrintBook(Book& book) {
    cout << "Title: " << book.GetTitle() << " by " << book.GetAuthor() << '\n';
}

Book CreateBook() {
    Book book = Book("Some book", "Some Author", 234);
    return book;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Book book = Book("Kobzar", "Taras Shevchenko", 260);
    PrintBook(book);
    Book book2 = book;
}

