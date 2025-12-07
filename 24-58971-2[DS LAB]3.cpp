#include <iostream>
using namespace std;

int main(){

    int arr[20];
    int i;

    cout<<"Enter 15 sorted numbers:\n";
    for(i=0;i<15;i++){
        cin>>arr[i];
    }

    int a,b,c;
    cout<<"Enter 3 numbers to search:\n";
    cin>>a>>b>>c;

    int x[3]={a,b,c};

    for(int t=0;t<3;t++){

        int key = x[t];
        int cmp1=0;
        int pos1=-1;


        for(i=0;i<15;i++){
            cmp1++;
            if(arr[i]==key){
                pos1=i;
                break;
            }
        }

        int left=0,right=14,mid,cmp2=0,pos2=-1;

        while(left<=right){
            mid=(left+right)/2;
            cmp2++;

            if(arr[mid]==key){
                pos2=mid;
                break;
            }
            else if(key<arr[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        cout<<"\nSearching "<<key<<endl;
        cout<<"Linear: index="<<pos1<<" comparisons="<<cmp1<<endl;
        cout<<"Binary: index="<<pos2<<" comparisons="<<cmp2<<endl;
    }

    return 0;
}

