/* Python extension to generate prime numbers using Sieve of Eratosthenes.*/
#include <Python.h>
#include "primesieve.h"

/* Create sieve and load it into PyList object */
static PyObject* primesieve_primesieve(PyObject* self, PyObject* args) {
  unsigned long long int limit;
  if (! PyArg_ParseTuple(args, "K", &limit))
      return NULL;
  unsigned char* comp = primesieve(limit);
  PyObject* comp_list = PyList_New(limit);
  unsigned long long int i;
  for (i = 0; i < limit; ++i)
    PyList_SET_ITEM(comp_list, i, PyBool_FromLong(comp[i]));
  free(comp);
  return comp_list;
}

/* Method table */
static PyMethodDef primesieve_methods[] = {
  { "primesieve", primesieve_primesieve, METH_VARARGS,
    "primesieve(unsigned long long int limit):\n"
    "  Returns list of bools of length limit.\n"
    "  For every index:\n"
    "    True indicates a composite value,\n"
    "    False a prime.", },
  { NULL, NULL, 0, NULL }           /* Sentinel */
};

static struct PyModuleDef primesievemodule = {
  PyModuleDef_HEAD_INIT,
  "primesieve",
  "Generate prime numbers using Sieve of Eratosthenes.",
  -1,
  primesieve_methods
};

PyMODINIT_FUNC PyInit_primesieve(void) {
  return PyModule_Create(&primesievemodule);
}
