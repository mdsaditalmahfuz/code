#include <iostream>
using namespace std;

int main() {

    int arr[50];
    int i,n=10;

    cout<<"Enter 10 numbers:\n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Array = ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int j;
    cout<<"Insert at beginning: ";
    cin>>j;

    for(i=n;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=j;
    n++;

    cout<<"After inserting at beginning: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    int pos;
    cout<<"Enter value and position to insert: ";
    cin>>x>>pos;

    for(i=n;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=j;
    n++;

    cout<<"After inserting in middle: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    cout<<"Insert at end: ";
    cin>>j;

    arr[n]=j;
    n++;

    cout<<"After inserting at end: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Delete from beginning.\n";
    for(i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;

    cout<<"After deleting beginning: ";
    for(i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;


    cout<<"Enter delete position: ";
    cin>>pos;
    for(i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;

    cout<<"After deleting middle: ";
    for(i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;



    n--;

    cout<<"After deleting end: ";
    for(i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

