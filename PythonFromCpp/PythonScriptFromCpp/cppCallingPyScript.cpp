#if __RunCommand__
g++ -o azm pythonStringFromCpp.cpp -I/usr/include/python2.7/ -lpython2.7
#endif

#include <iostream>
#include <stdio.h>
#include <Python.h>

using namespace std;

int main()
{
    FILE *file;
    cout << "We will call python script to find today's date" << endl;
 
    file = fopen("localTime.py", "r");
    
    Py_Initialize();
    PyRun_SimpleFile(file, "localTime.py");
    Py_Finalize();

    return 0;
}

