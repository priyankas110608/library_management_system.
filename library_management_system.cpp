#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int bId, string bTitle, string bAuthor) {
        id = bId;
        title = bTitle;
        author = bAuthor;
        issued = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "Book Added Successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo books available.\n";
            return;
        }

        cout << "\n===== Book List =====\n";

        for (auto &book : books) {
            cout << "ID: " << book.id << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Status: "
                 << (book.issued ? "Issued" : "Available")
                 << endl;
            cout << "----------------------\n";
        }
    }

    void issueBook() {
        int id;
        cout << "\nEnter Book ID to Issue: ";
        cin >> id;

        for (auto &book : books) {
            if (book.id == id) {
                if (!book.issued) {
                    book.issued = true;
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book already issued.\n";
                }
                return;
            }
        }

        cout << "Book not found.\n";
    }

    void returnBook() {
        int id;
        cout << "\nEnter Book ID to Return: ";
        cin >> id;

        for (auto &book : books) {
            if (book.id == id) {
                if (book.issued) {
                    book.issued = false;
                    cout << "Book Returned Successfully!\n";
                } else {
                    cout << "Book was not issued.\n";
                }
                return;
            }
        }

        cout << "Book not found.\n";
    }

    void searchBook() {
        int choice;
        cout << "\nSearch By:\n";
        cout << "1. Title\n";
        cout << "2. Author\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        string keyword;
        cout << "Enter search text: ";
        getline(cin, keyword);

        bool found = false;

        for (auto &book : books) {
            if ((choice == 1 && book.title == keyword) ||
                (choice == 2 && book.author == keyword)) {

                cout << "\nBook Found!\n";
                cout << "ID: " << book.id << endl;
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Status: "
                     << (book.issued ? "Issued" : "Available")
                     << endl;

                found = true;
            }
        }

        if (!found) {
            cout << "No matching book found.\n";
        }
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lib.addBook();
            break;

        case 2:
            lib.displayBooks();
            break;

        case 3:
            lib.issueBook();
            break;

        case 4:
            lib.returnBook();
            break;

        case 5:
            lib.searchBook();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}
