#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[24];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_mypyc_fib_internal;
extern CPyModule *CPyModule_mypyc_fib;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_numpy___typing;
extern CPyModule *CPyModule_typing;
extern CPyTagged CPyDef_fib_mypyc(CPyTagged cpy_r_n);
extern PyObject *CPyPy_fib_mypyc(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern CPyTagged CPyDef_fib_np_mypyc(CPyTagged cpy_r_n);
extern PyObject *CPyPy_fib_np_mypyc(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
