#include <iostream>
using namespace std;

int main(){

    int arr[20];
    int i,j,key,cmp=0,sh=0;

    cout<<"Enter 12 numbers:\n";
    for(i=0;i<12;i++){
        cin>>arr[i];
    }

    for(i=1;i<12;i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key){
            cmp++;
            arr[j+1] = arr[j];
            sh++;
            j--;
        }

        if(j>=0) cmp++;

        arr[j+1] = key;
        sh++;

        cout<<"Pass "<<i<<": ";
        for(int k=0;k<12;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }

    cout<<"Total comparisons = "<<cmp<<endl;
    cout<<"Total shifts = "<<sh<<endl;

    return 0;
}

