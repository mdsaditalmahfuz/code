#include <iostream>
using namespace std;

class node
{

public:
    int Data;
    node*pre;
    node*next;

    node (int value)
    {
        Data=value;
        pre= NULL;
        next=NULL;
    }

};
void insertAtLast(node* &head, int value)
{
     node* newNode = new node(value);
     node* temp = head;
     if (head==nullptr){insertAtHead(head,value);
        return;
     }

     while (temp-> next!=NULL) {
        temp = temp ->next;
     }
     temp -> next = newNode;
     temp = newNode ->pre;
}

void insertAtHead (node* &head, int value)
{
    node* newNode = new node(value);
    node* temp = head;
    newNode->next = head;
    if(head!=NULL) {
        head-> pre = newNode;
    }
    head = newNode;


}


void showDetails(node* &head) {
node* temp = head;
while (temp!=NULL) {

    cout << temp -> data << " -> ";
    temp = temp ->next;}

    cout << "NULL" <<endl;
}

int main () {
node* head = NULL;
insertAtHead(head,7);
insertAtHead(head,15);
insertAtHead(head,22);
insertAtHead(head,30);
insertAtHead(head,38);
insertAtHead(head,42);
showDetails(head);

insertAtLast(head,55);
showDetails(head);



}


