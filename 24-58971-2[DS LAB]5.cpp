#include <iostream>
using namespace std;

int main(){

    int *p;
    p = new int[6];

    cout<<"Enter 6 numbers:\n";
    for(int i=0;i<6;i++){
        cin>>p[i];
    }


    for(int i=0;i<6;i++){
        p[i] = p[i] * 2;
    }

    cout<<"After doubling: ";
    for(int i=0;i<6;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;

    delete[] p;

    return 0;
}

