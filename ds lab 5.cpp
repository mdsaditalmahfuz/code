#include <iostream>
using namespace std;

int main() {
    char str[100];
    char *p, *start, *end, temp;
    int length = 0;

    cout << "Enter a string: ";
    cin >> str;

    p = str;
    while (*p != '\0') {
        length++;
        p++;
    }

    cout << "Length of the string = " << length << endl;

    start = str;
    end = str + length - 1;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    cout << "Reversed string = " << str << endl;

    return 0;
}
