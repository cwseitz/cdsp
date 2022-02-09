#include <Python.h>
#include <numpy/arrayobject.h>
#include <stdio.h>


static PyObject* sinusoid(PyObject* Py_UNUSED(self), PyObject* args) {

  PyObject* list;

  if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &list))
    return NULL;

    double low = PyFloat_AsDouble(PyList_GetItem(list, 0));
    double high = PyFloat_AsDouble(PyList_GetItem(list, 1));
    int n = PyFloat_AsDouble(PyList_GetItem(list, 2));
    double dt = (high-low)/n;
    double* tptr = malloc(n * sizeof(double));
    double* sptr = malloc(n * sizeof(double));
    int i;

    for (i = 1; i < n; i++){
            tptr[i] = tptr[i-1] + dt;
            sptr[i] = sin(tptr[i]);
    }

    //duplicate for python (inefficient)
    PyObject *tlist = PyList_New(n);
    PyObject *slist = PyList_New(n);

    for (int i = 0; i < n; ++i) {
       PyList_SET_ITEM(tlist, i, PyFloat_FromDouble(tptr[i]));
       PyList_SET_ITEM(slist, i, PyFloat_FromDouble(sptr[i]));
    }
    
    
    free(sptr);
    free(tptr);

    return Py_BuildValue("(OO)",tlist,slist);
}
