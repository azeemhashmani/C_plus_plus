#include <Python.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

    Py_Initialize();

    //Make sure to have MyCpp.cpp and MyPython.py in same directory
    // and give the path in 2nd arg of func sys.path.insert
    PyRun_SimpleString ("import sys; sys.path.insert(0, '/home/azeemali/github/Cpp/PythonFromCpp/PythonFileFromCppRetValues')");
    PyObject * pModule = NULL;
    PyObject * pFunc   = NULL;
    PyObject * pResult = NULL;

    pModule = PyImport_ImportModule("MyPython");
    pFunc   = PyObject_GetAttrString(pModule, "Hello");
    
    if(pFunc != NULL) {
        pResult = PyObject_CallObject(pFunc, NULL);
       
       if (pResult != NULL)
       { 
            double result = PyFloat_AsDouble(pResult);
            printf ("Result = %f \n", result);
            Py_Finalize();
       }
       else
       {
            printf("pResult returned NULL\n");
       }
    }
    else {
        printf("pFunc returned NULL\n");
    }

    return 0;
}
