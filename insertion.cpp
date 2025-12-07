#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n = 5;

    cout << "Enter 5 integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int num, pos;
    cout << "Enter number to insert: ";
    cin >> num;
    cout << "Enter position to insert (1 to " << n + 1 << "): ";
    cin >> pos;

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = num;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int delPos;
    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> delPos;

    for (int i = delPos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;


    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

