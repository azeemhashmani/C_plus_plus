#include <Python.h>
#include <stdio.h>

int main()
{

    Py_Initialize();

    //Make sure to have MyCpp.cpp and MyPython.py in same directory
    // and give the path in 2nd arg of func sys.path.insert
    PyRun_SimpleString ("import sys; sys.path.insert(0, '/home/azeemali/github/Cpp/PythonFromCpp/PythonFileFromCpp')");
    PyObject * pModule = NULL;
    PyObject * pFunc   = NULL;

    pModule = PyImport_ImportModule("MyPython");
    pFunc   = PyObject_GetAttrString(pModule, "Hello");
    if(pFunc != NULL) {
        PyEval_CallObject(pFunc, NULL);
        Py_Finalize();
    }
    else {
        printf("pFunc returned NULL\n");
    }

    return 0;
}
