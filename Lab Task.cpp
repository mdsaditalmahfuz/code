#include <iostream>
using namespace std;

struct Song {
    string name;
    string singer;
    float duration;
    Song* next;
    Song* prev;
};

Song* head = nullptr;
Song* tail = nullptr;

// Function to insert at end
void insertSong(string name, string singer, float duration) {
    Song* newSong = new Song{name, singer, duration, nullptr, nullptr};
    if (!head) {
        head = tail = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
}

// Function to display songs
void displayList() {
    Song* temp = head;
    cout << "Doubly Linked List: ";
    while (temp) {
        cout << "(" << temp->name << ", " << temp->singer << ", " << temp->duration << ") <--> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to find song with highest duration
void findMaxDuration() {
    Song* temp = head;
    float maxDur = -1;
    int position = 0, maxPos = 0;
    Song* maxSong = nullptr;

    while (temp) {
        if (temp->duration > maxDur) {
            maxDur = temp->duration;
            maxSong = temp;
            maxPos = position;
        }
        position++;
        temp = temp->next;
    }


}




