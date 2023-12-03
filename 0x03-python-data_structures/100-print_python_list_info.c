/*#include <stdlib.h>
#include <stdio.h>
#include <Python.h>*/
/**
 * print_python_list_info -  function that prints some basic
 *							info about Python lists
 * @p: python list
 */
/*void print_python_list_info(PyObject *p)
{
	int elem;

	printf("[*] Size of the Python List = %lu\n", Py_SIZE(p));
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (elem = 0; elem < Py_SIZE(p); elem++)
		printf("Element %d: %s\n", elem, Py_TYPE(PyList_GetItem(p, elem))->tp_name);
}*/

#include <Python.h>
#include "object.h"
#include "listobject.h"

void printListInfo(PyObject* list) {
    // Check if the passed object is a list
    if (!PyList_Check(list)) {
        printf("The provided object is not a list.\n");
        return;
    }

    // Get the length of the list
    Py_ssize_t listLength = PyList_Size(list);

    printf("List Length: %zd\n", listLength);

    // Print each element of the list
    printf("List Elements:\n");
    for (Py_ssize_t i = 0; i < listLength; ++i) {
        PyObject* item = PyList_GetItem(list, i);
        printf("[%zd]: ", i);

        // Print the element
        PyObject_Print(item, stdout, 0);
        printf("\n");

        // Decrement the reference count of the item
        Py_DECREF(item);
    }
}

int main() {
    // Initialize Python interpreter
    Py_Initialize();

    // Create a Python list
    PyObject* pyList = PyList_New(0); // Create an empty list

    // Append elements to the list
    PyList_Append(pyList, PyLong_FromLong(10));
    PyList_Append(pyList, PyUnicode_FromString("Hello"));
    PyList_Append(pyList, PyFloat_FromDouble(3.14));

    // Call the function to print list info
    printListInfo(pyList);

    // Clean up
    Py_DECREF(pyList); // Release the Python list object

    // Finalize Python interpreter
    Py_Finalize();

    return 0;
}

