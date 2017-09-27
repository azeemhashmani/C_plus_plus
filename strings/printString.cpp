/*
c_str() returns pointer to an array that contains a null-terminated sequence of characters(ie., C-string).

This array includes the samne sequence of characters that make up the value of string object plus additional terminating null-character ('\0') at end
*/


#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string someString("This is someting in string");

    cout << someString << endl;
    printf("%s \n", someString.c_str());

    return 0;
}
