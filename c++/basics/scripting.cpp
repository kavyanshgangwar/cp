#include <bits/stdc++.h>
#include <Python.h>
using namespace std;
int main(){
  PyObject* pInt;

	Py_Initialize();

	PyRun_SimpleString("print('Hello World from Embedded Python!!!')");
	
	Py_Finalize();
}