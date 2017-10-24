#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    char ipAddr[12] = {'\0'};
    int  incr = 125;

    incr++;

    sprintf(ipAddr, "10.86.%d.0", incr);

    string sIpAddr(&ipAddr[0]);

    // Or sIpAddr = ipAddr; initialization after declaration
    cout << sIpAddr << endl;

   return 0;

}
