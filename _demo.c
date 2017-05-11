#include <Python.h>
#include <demo.h>

static char demo_doc[] = "Examples for C/C++ python wrapping";


/*
 * Exported Methods declarations
 */
static PyObject* wrapper_echo(PyObject *self, PyObject *args);
static PyObject* wrapper_now(PyObject *self, PyObject *args);
static PyObject* wrapper_addition(PyObject *self, PyObject *args);

/*
 * Methods exported by this module
 */
static PyMethodDef demo_methods[] = {
    {"echo",  wrapper_echo, METH_VARARGS},
    {"now",  wrapper_now, METH_VARARGS},
    {"addition",  wrapper_addition, METH_VARARGS},
    {NULL,      NULL}        /* Sentinel */
};


/* ! the struct name must respect the format: <name of the module> followed by string "module"*/
static struct PyModuleDef demomodule = {
   PyModuleDef_HEAD_INIT,
   "demo",   /* name of module */
   demo_doc, /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   demo_methods
};


/*
 * Module initialization
 */
#if PY_MAJOR_VERSION >= 3
    PyMODINIT_FUNC PyInit_demo(void)
#else
    PyMODINIT_FUNC initdemo(void)
#endif
{
#if PY_MAJOR_VERSION >= 3
    return PyModule_Create(&demomodule);
#else
    (void) Py_InitModule("demo", demo_methods);
#endif
}

/*
 * Methods definition
 */

PyObject* wrapper_echo(PyObject *self, PyObject *args)
{
    char *message = NULL;
    char *echoed = NULL;
    if (!PyArg_ParseTuple(args, "s", &message))
        Py_RETURN_NONE;

    echoed = echo(message);
    return Py_BuildValue("s", echoed);
}


PyObject* wrapper_now(PyObject *self, PyObject *args){

    PyObject* ret = NULL;
    struct tm *tm = now();

    ret = Py_BuildValue("{"
        " s:i,"
        " s:i,"
        " s:i,"
        " s:i,"
        " s:i,"
        " s:i"
        "}",
        "year", tm->tm_year + 1900,
        "month", tm->tm_mon + 1,
        "day", tm->tm_mday,
        "hour", tm->tm_hour,
        "minute", tm->tm_min,
        "second", tm->tm_sec
    );
    return ret;
}


PyObject* wrapper_addition(PyObject *self, PyObject *args){
    long a;
    long b;
    long sum;

    if(!PyArg_ParseTuple(args, "ll", &a, &b))
        Py_RETURN_NONE;

    sum = a + b;
    return PyLong_FromLong(sum);
}