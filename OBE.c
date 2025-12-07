#include <iostream>
using namespace std;

// Define the structure of a node
struct Node {
    int stop;
    Node* next;
};

// Function to create a new node
Node* createNode(int stop) {
    Node* newNode = new Node();
    newNode->stop = stop;
    newNode->next = nullptr;
    return newNode;
}

// Function to print the list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->stop;
        if (current->next != nullptr) cout << " → ";
        current = current->next;
    }
    cout << endl;
}

// Function to delete a node by value
void deleteStop(Node*& head, int value) {
    if (head == nullptr) return;

    if (head->stop == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->stop != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

// Function to insert a node after a given stop
void insertAfter(Node* head, int afterStop, int newStop) {
    Node* current = head;
    while (current != nullptr && current->stop != afterStop) {
        current = current->next;
    }

    if (current != nullptr) {
        Node* newNode = createNode(newStop);
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    // Step 1: Create the initial route: 10 → 12 → 15 → 22 → 30
    Node* head = createNode(10);
    head->next = createNode(12);
    head->next->next = createNode(15);
    head->next->next->next = createNode(22);
    head->next->next->next->next = createNode(30);

    // Step 2: Remove stop 15
    deleteStop(head, 15);

    // Step 3: Insert stop 25 after 22
    insertAfter(head, 22, 25);

    // Step 4: Display the updated route
    cout << "Updated Bus Route: ";
    printList(head);

    return 0;
}
