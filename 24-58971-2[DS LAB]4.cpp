#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* insertAtHead(Node *head, int value)
{
    Node *n = new Node;
    n->data = value;
    n->next = head;
    return n;
}

Node* insertAfterNode(Node *head, int prevValue, int newValue)
{
    Node *temp = head;

    while(temp != NULL)
    {
        if(temp->data == prevValue)
        {
            Node *n = new Node;
            n->data = newValue;
            n->next = temp->next;
            temp->next = n;
            break;
        }
        temp = temp->next;
    }

    return head;
}


Node* deleteNode(Node *head, int value)
{
    if(head == NULL)
        return head;


    if(head->data == value)
    {
        Node *d = head;
        head = head->next;
        delete d;
        return head;
    }

    Node *prev = head;
    Node *curr = head->next;

    while(curr != NULL)
    {
        if(curr->data == value)
        {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

int search(Node *head, int value)
{
    Node *temp = head;

    while(temp != NULL)
    {
        if(temp->data == value)
            return 1;

        temp = temp->next;
    }
    return 0;
}

int display(Node *head)
{
    Node *t = head;

    while(t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }

    cout << endl;
    return 1;
}

int main()
{
    Node *head = NULL;

    head = insertAtHead(head, 40);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 10);

    cout << "After inserting 10,20,30,40: ";
    display(head);

    head = insertAfterNode(head, 20, 25);
    cout << "After inserting 25 after 20: ";
    display(head);

    head = deleteNode(head, 30);
    cout << "After deleting 30: ";
    display(head);

    if(search(head, 25))
        cout << "25 found" << endl;
    else
        cout << "25 not found" << endl;

    if(search(head, 35))
        cout << "35 found" << endl;
    else
        cout << "35 not found" << endl;

    return 0;
}
