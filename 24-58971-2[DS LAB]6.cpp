#include <iostream>
using namespace std;

int stringLength(char s[])
{
    int L = 0;
    while(s[L] != '\0')
    {
        L++;
    }
    return L;
}

int stringCopy(char dest[], char src[])
{
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return 1;
}

int stringCompare(char a[], char b[])
{
    int i = 0;

    while(a[i] != '\0' && b[i] != '\0')
    {
        if(a[i] != b[i])
        {
            return 1;
        }
        i++;
    }

    if(a[i] == '\0' && b[i] == '\0')
        return 0;
    else
        return 1;
}

int stringConcat(char a[], char b[])
{
    int i = 0;
    while(a[i] != '\0')
    {
        i++;
    }

    int j = 0;
    while(b[j] != '\0')
    {
        a[i] = b[j];
        i++;
        j++;
    }

    a[i] = '\0';
    return 1;
}

int main()
{
    char s1[100], s2[100], copied[100];

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    cout << "Length of s1 = " << stringLength(s1) << endl;
    cout << "Length of s2 = " << stringLength(s2) << endl;

    stringCopy(copied, s1);
    cout << "Copied string = " << copied << endl;

    int check = stringCompare(s1, s2);
    if(check == 0)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are not equal" << endl;

    stringConcat(s1, s2);
    cout << "After concatenation: " << s1 << endl;

    return 0;
}
