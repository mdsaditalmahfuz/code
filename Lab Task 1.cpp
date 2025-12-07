#include <iostream>
using namespace std;

struct Book {
    int id;
    string name;
    int days;
    Book* next;
};

Book* head = nullptr;

// Insert book at end
void insertBook(int id, string name, int days) {
    Book* newBook = new Book{id, name, days, nullptr};
    if (!head) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

// Display list
void displayList() {
    Book* temp = head;
    cout << "Linked List: ";
    while (temp) {
        cout << "(" << temp->id << ", " << temp->name << ", " << temp->days << ") -> ";
        temp = temp->next;
    }
    cout << "Null\n";
}

