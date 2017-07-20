#include <iostream>
#include <map>

using namespace std;

int main()
{
    map <char, int> mymap;
    map <char, int> :: iterator it;

    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;

    it = mymap.find ('z');

    if (it != mymap.end())
    {
        cout << "z not found" << endl;
    }
    else
    {
       cout << "z found" << endl;
    }

    it = mymap.find ('b');
    
    if (it != mymap.end())
    {
        cout << "b not found" << endl;
    }
    else
    {
       cout << "z found" << endl;
    }
}
