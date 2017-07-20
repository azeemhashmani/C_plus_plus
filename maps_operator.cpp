#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<char, int> mymap;
    mymap['a'] = 3;
    mymap['b'] = 4;
    mymap['c'] = mymap['a'];
    mymap['e'];

    cout << mymap.size() << endl;
   
    return 0;
}
