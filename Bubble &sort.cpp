#include <iostream>
using namespace std;

int main() {
    int arr[6];
    cout << "Enter 6 integers: ";
    for(int i = 0; i < 6; i++)
        cin >> arr[i];

    cout << "\nInitial array: ";
    for(int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;


    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5 - i; j++) {
            if(arr[j] > arr[j+1]) {

                int swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }


        cout << "After pass " << i + 1 << ": ";
        for(int k = 0; k < 6; k++)
            cout << arr[k] << " ";
        cout << endl;
    }

    cout << "\nSorted array: ";
    for(int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
