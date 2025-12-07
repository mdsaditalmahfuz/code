#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = arr[0];
    int smallest = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > largest)
            largest = arr[i];
        if(arr[i] < smallest)
            smallest = arr[i];
    }

    cout << "Largest number = " << largest << endl;
    cout << "Smallest number = " << smallest << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;


    cout << "Enter how many numbers: ";
    cin >> n;

    int arr[n];


    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    cout << "Array in reverse order: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}
write a c++ programe to sort an array of n integers in ascending order using the bouble sort algprithom it solve it array wise manully
