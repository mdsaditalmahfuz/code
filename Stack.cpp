#include<iostream>
using namespace std;
class stack
{
public:
    int* arr;
    int size =50;
    int topElement;
    stack()
    {
        arr =new int[size];
        topElement = -1;
    }
    void push (int a)
    {
        if(topElement == size-1)
        {
            cout<<"stack full..Get lost";
            return;
        }
        topElement++;
        arr[topElement] =a;
    }
    void pop()
    {
        if(topElement ==-1)
        {
            cout<<"Stack empty. Get Lost..";
            return;
        }
        topElement--;
    }
};
