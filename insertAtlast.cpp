#include<iostream>
using namespace std;
class  node
{
  public:
      int data;

      node*next;

      node(int value)
      {
          data=value;
          next=nullptr;
      }
};

void insertAtlast(node*&head,int value)

{
   node*newnode= new node(value);
   if(head==nullptr)
   {
       head=newnode;
       return;
   }
   node*temp=head;

   while(temp->next !=nullptr)
   {
      temp= temp->next;
   }
   temp->next=newnode;
}
void display(node*head)
{
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<" Null";
}
 int main ()
 {
     node*head=nullptr;


     insertatlast(head,10);
     insertatlast(head,20);
     insertatlast(head,30);
     insertatlast(head,40);
     insertatlast(head,50);

     cout<<"Linked List: ";
     diplay(head);


 }
