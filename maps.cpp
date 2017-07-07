#include <iostream>
#include <map>

using namespace std;

int main()
{
   map <char, int> mymap;
   map <char, int> :: iterator it;

   mymap['a'] = 100;
   mymap['b'] = 200;
   mymap['c'] = 300;

   for (it = mymap.begin(); it != mymap.end(); it++)
   {
       cout << it->first << " ==> " << it->second << endl;
   }

   return 0;
}    
