#if __RunCommand__
g++ -o azm pythonStringFromCpp.cpp -I/usr/include/python2.7/ -lpython2.7
#endif



#include <iostream>
#include <Python.h>

using namespace std;

int main()
{
    cout << "We will call python to find today's date" << endl;

    Py_Initialize();
    PyRun_SimpleString("from time import time,ctime\n"
                     "print 'Today is',ctime(time())\n");
    Py_Finalize();
    
    return 0;
}
