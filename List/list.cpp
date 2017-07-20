#include <iostream>
#include <list>

using namespace std;

int main()
{
  
    list <int> mylist(3, 11); // Create three ints with value 11
    list <int> :: iterator it;   

    cout << "Data Initialized : 11, 11, 11" << endl;
    // PUSH FRONT
    mylist.push_front(10);
    mylist.push_front(9);
    
   cout << "Data after push front : ";

    for (it = mylist.begin(); it != mylist.end(); it++)
    {
        cout << *it << " ";
    }
    // Output 9, 10, 11, 11, 11

   // PUSH BACK
   mylist.push_back(12);
   mylist.push_back(13);

    cout << "Data after push back : ";

    for (it = mylist.begin(); it != mylist.end(); it++)
    {
        cout << *it << " ";
    }
    // Output 9, 10, 11, 11, 11, 12, 13
    
   // POP FRONT doesn't return anything by default so we have to use .front if you want to print before pop
   mylist.pop_front();
   
   cout << "Data after pop front: ";
   for (it = mylist.begin(); it != mylist.end(); it++)
   {
       cout << *it << " ";
   }
   // Output  10, 11, 11, 11, 12, 13

   // POP BACK doesn't return anything by default so we have to use .back() if you wan to to print before pop
   mylist.pop_back();

   cout << "Data after pop back : ";
   
   for (it = mylist.begin(); it != mylist.end(); it++)
   {
       cout << *it << " ";
   }
   // Output  10, 11, 11, 11, 12
  
  return 0;
}
