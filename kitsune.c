#include <Python.h>
#include <stdio.h>
#include "sinusoid.c"
#include <numpy/arrayobject.h>

static PyMethodDef KitMethods[] = {
    {"sinusoid", sinusoid, METH_VARARGS, "Generate a sinusoid in C"},
    {NULL, NULL, 0, NULL},
};


static struct PyModuleDef kitsune = {
    PyModuleDef_HEAD_INIT,
    "kitsune",
    "DSP in C",
    -1,
    KitMethods
};

PyMODINIT_FUNC PyInit_kitsune(void) {
    import_array();
    return PyModule_Create(&kitsune);
}
