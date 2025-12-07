
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];
    int rowSum, colSum;


    cout << "Enter elements of 3x3 matrix:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nThe matrix is:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }


    cout << "\nSum of each row:\n";
    for(int i = 0; i < 3; i++) {
        rowSum = 0;
        for(int j = 0; j < 3; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i+1 << " = " << rowSum << endl;
    }


    cout << "\nSum of each column:\n";
    for(int j = 0; j < 3; j++) {
        colSum = 0;
        for(int i = 0; i < 3; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j+1 << " = " << colSum << endl;
    }

    cout<<endl;
}
