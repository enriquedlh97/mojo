#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "__native.h"
#include "__native_internal.h"
static PyMethodDef module_methods[] = {
    {"fib_mypyc", (PyCFunction)CPyPy_fib_mypyc, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"fib_np_mypyc", (PyCFunction)CPyPy_fib_np_mypyc, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "mypyc_fib",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_mypyc_fib(void)
{
    PyObject* modname = NULL;
    if (CPyModule_mypyc_fib_internal) {
        Py_INCREF(CPyModule_mypyc_fib_internal);
        return CPyModule_mypyc_fib_internal;
    }
    CPyModule_mypyc_fib_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_mypyc_fib_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_mypyc_fib_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_mypyc_fib_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_mypyc_fib_internal;
    fail:
    Py_CLEAR(CPyModule_mypyc_fib_internal);
    Py_CLEAR(modname);
    return NULL;
}

CPyTagged CPyDef_fib_mypyc(CPyTagged cpy_r_n) {
    int64_t cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    CPyTagged cpy_r_r4;
    CPyTagged cpy_r_r5;
    CPyTagged cpy_r_r6;
    CPyTagged cpy_r_r7;
    CPyTagged cpy_r_r8;
    CPyTagged cpy_r_r9;
    CPyTagged cpy_r_r10;
    cpy_r_r0 = cpy_r_n & 1;
    cpy_r_r1 = cpy_r_r0 != 0;
    if (!cpy_r_r1) goto CPyL2;
    cpy_r_r2 = CPyTagged_IsLt_(cpy_r_n, 4);
    if (cpy_r_r2) {
        goto CPyL3;
    } else
        goto CPyL4;
CPyL2: ;
    cpy_r_r3 = (Py_ssize_t)cpy_r_n < (Py_ssize_t)4;
    if (!cpy_r_r3) goto CPyL4;
CPyL3: ;
    CPyTagged_INCREF(cpy_r_n);
    cpy_r_r4 = cpy_r_n;
    goto CPyL7;
CPyL4: ;
    cpy_r_r5 = CPyTagged_Subtract(cpy_r_n, 2);
    cpy_r_r6 = CPyDef_fib_mypyc(cpy_r_r5);
    CPyTagged_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == CPY_INT_TAG)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_mypyc", 7, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r7 = CPyTagged_Subtract(cpy_r_n, 4);
    cpy_r_r8 = CPyDef_fib_mypyc(cpy_r_r7);
    CPyTagged_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == CPY_INT_TAG)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_mypyc", 7, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r9 = CPyTagged_Add(cpy_r_r6, cpy_r_r8);
    CPyTagged_DECREF(cpy_r_r6);
    CPyTagged_DECREF(cpy_r_r8);
    cpy_r_r4 = cpy_r_r9;
CPyL7: ;
    return cpy_r_r4;
CPyL8: ;
    cpy_r_r10 = CPY_INT_TAG;
    return cpy_r_r10;
CPyL9: ;
    CPyTagged_DecRef(cpy_r_r6);
    goto CPyL8;
}

PyObject *CPyPy_fib_mypyc(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"n", 0};
    static CPyArg_Parser parser = {"O:fib_mypyc", kwlist, 0};
    PyObject *obj_n;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_n)) {
        return NULL;
    }
    CPyTagged arg_n;
    if (likely(PyLong_Check(obj_n)))
        arg_n = CPyTagged_BorrowFromObject(obj_n);
    else {
        CPy_TypeError("int", obj_n); goto fail;
    }
    CPyTagged retval = CPyDef_fib_mypyc(arg_n);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("mypyc_fib.py", "fib_mypyc", 6, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef_fib_np_mypyc(CPyTagged cpy_r_n) {
    int64_t cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    CPyPtr cpy_r_r8;
    CPyPtr cpy_r_r9;
    CPyPtr cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    CPyPtr cpy_r_r16;
    PyObject *cpy_r_r17;
    CPyPtr cpy_r_r18;
    CPyPtr cpy_r_r19;
    CPyPtr cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_matrix;
    CPyTagged cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_result;
    tuple_T2II cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    CPyTagged cpy_r_r48;
    CPyTagged cpy_r_r49;
    cpy_r_r0 = cpy_r_n & 1;
    cpy_r_r1 = cpy_r_r0 != 0;
    if (!cpy_r_r1) goto CPyL2;
    cpy_r_r2 = CPyTagged_IsLt_(0, cpy_r_n);
    if (cpy_r_r2) {
        goto CPyL4;
    } else
        goto CPyL3;
CPyL2: ;
    cpy_r_r3 = (Py_ssize_t)cpy_r_n <= (Py_ssize_t)0;
    if (!cpy_r_r3) goto CPyL4;
CPyL3: ;
    return 0;
CPyL4: ;
    cpy_r_r4 = cpy_r_n == 2;
    if (!cpy_r_r4) goto CPyL6;
    return 2;
CPyL6: ;
    cpy_r_r5 = PyList_New(2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 17, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r6 = CPyStatics[17]; /* 1 */
    cpy_r_r7 = CPyStatics[17]; /* 1 */
    cpy_r_r8 = (CPyPtr)&((PyListObject *)cpy_r_r5)->ob_item;
    cpy_r_r9 = *(CPyPtr *)cpy_r_r8;
    CPy_INCREF(cpy_r_r6);
    *(PyObject * *)cpy_r_r9 = cpy_r_r6;
    cpy_r_r10 = cpy_r_r9 + 8;
    CPy_INCREF(cpy_r_r7);
    *(PyObject * *)cpy_r_r10 = cpy_r_r7;
    cpy_r_r11 = PyList_New(2);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 18, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r12 = CPyStatics[17]; /* 1 */
    cpy_r_r13 = CPyStatics[18]; /* 0 */
    cpy_r_r14 = (CPyPtr)&((PyListObject *)cpy_r_r11)->ob_item;
    cpy_r_r15 = *(CPyPtr *)cpy_r_r14;
    CPy_INCREF(cpy_r_r12);
    *(PyObject * *)cpy_r_r15 = cpy_r_r12;
    cpy_r_r16 = cpy_r_r15 + 8;
    CPy_INCREF(cpy_r_r13);
    *(PyObject * *)cpy_r_r16 = cpy_r_r13;
    cpy_r_r17 = PyList_New(2);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 16, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r18 = (CPyPtr)&((PyListObject *)cpy_r_r17)->ob_item;
    cpy_r_r19 = *(CPyPtr *)cpy_r_r18;
    *(PyObject * *)cpy_r_r19 = cpy_r_r5;
    cpy_r_r20 = cpy_r_r19 + 8;
    *(PyObject * *)cpy_r_r20 = cpy_r_r11;
    cpy_r_r21 = CPyModule_numpy;
    cpy_r_r22 = CPyStatics[3]; /* 'int64' */
    cpy_r_r23 = CPyObject_GetAttr(cpy_r_r21, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 20, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_r24 = CPyModule_numpy;
    cpy_r_r25 = CPyStatics[4]; /* 'array' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 15, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r27[2] = {cpy_r_r17, cpy_r_r23};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = CPyStatics[19]; /* ('dtype',) */
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r26, cpy_r_r28, 1, cpy_r_r29);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 15, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF(cpy_r_r17);
    CPy_DECREF(cpy_r_r23);
    cpy_r_matrix = cpy_r_r30;
    cpy_r_r31 = CPyTagged_Subtract(cpy_r_n, 2);
    cpy_r_r32 = CPyModule_numpy;
    cpy_r_r33 = CPyStatics[6]; /* 'linalg' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 23, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r35 = CPyStatics[7]; /* 'matrix_power' */
    cpy_r_r36 = CPyObject_GetAttr(cpy_r_r34, cpy_r_r35);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 23, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r37 = CPyTagged_StealAsObject(cpy_r_r31);
    PyObject *cpy_r_r38[2] = {cpy_r_matrix, cpy_r_r37};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r36, cpy_r_r39, 2, 0);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 23, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_matrix);
    CPy_DECREF(cpy_r_r37);
    cpy_r_result = cpy_r_r40;
    cpy_r_r41.f0 = 0;
    cpy_r_r41.f1 = 0;
    CPyTagged_INCREF(cpy_r_r41.f0);
    CPyTagged_INCREF(cpy_r_r41.f1);
    cpy_r_r42 = PyTuple_New(2);
    if (unlikely(cpy_r_r42 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = CPyTagged_StealAsObject(cpy_r_r41.f0);
    PyTuple_SET_ITEM(cpy_r_r42, 0, __tmp1);
    PyObject *__tmp2 = CPyTagged_StealAsObject(cpy_r_r41.f1);
    PyTuple_SET_ITEM(cpy_r_r42, 1, __tmp2);
    cpy_r_r43 = PyObject_GetItem(cpy_r_result, cpy_r_r42);
    CPy_DECREF(cpy_r_result);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 25, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r44 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r45[1] = {cpy_r_r43};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = _PyObject_Vectorcall(cpy_r_r44, cpy_r_r46, 1, 0);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 25, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_DECREF(cpy_r_r43);
    if (likely(PyLong_Check(cpy_r_r47)))
        cpy_r_r48 = CPyTagged_FromObject(cpy_r_r47);
    else {
        CPy_TypeError("int", cpy_r_r47); cpy_r_r48 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == CPY_INT_TAG)) {
        CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 25, CPyStatic_globals);
        goto CPyL19;
    }
    return cpy_r_r48;
CPyL19: ;
    cpy_r_r49 = CPY_INT_TAG;
    return cpy_r_r49;
CPyL20: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL19;
CPyL21: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r11);
    goto CPyL19;
CPyL22: ;
    CPy_DecRef(cpy_r_r17);
    goto CPyL19;
CPyL23: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r23);
    goto CPyL19;
CPyL24: ;
    CPy_DecRef(cpy_r_matrix);
    CPyTagged_DecRef(cpy_r_r31);
    goto CPyL19;
CPyL25: ;
    CPy_DecRef(cpy_r_matrix);
    CPy_DecRef(cpy_r_r37);
    goto CPyL19;
CPyL26: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL19;
}

PyObject *CPyPy_fib_np_mypyc(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"n", 0};
    static CPyArg_Parser parser = {"O:fib_np_mypyc", kwlist, 0};
    PyObject *obj_n;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_n)) {
        return NULL;
    }
    CPyTagged arg_n;
    if (likely(PyLong_Check(obj_n)))
        arg_n = CPyTagged_BorrowFromObject(obj_n);
    else {
        CPy_TypeError("int", obj_n); goto fail;
    }
    CPyTagged retval = CPyDef_fib_np_mypyc(arg_n);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("mypyc_fib.py", "fib_np_mypyc", 9, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[8]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "<module>", -1, CPyStatic_globals);
        goto CPyL7;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[21]; /* (('numpy', 'numpy', 'np'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[11]; /* 'mypyc_fib.py' */
    cpy_r_r13 = CPyStatics[12]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL7;
    cpy_r_r15 = CPyStatics[22]; /* ('NDArray',) */
    cpy_r_r16 = CPyStatics[14]; /* 'numpy.typing' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "<module>", 2, CPyStatic_globals);
        goto CPyL7;
    }
    CPyModule_numpy___typing = cpy_r_r18;
    CPy_INCREF(CPyModule_numpy___typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[23]; /* ('cast',) */
    cpy_r_r20 = CPyStatics[16]; /* 'typing' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("mypyc_fib.py", "<module>", 3, CPyStatic_globals);
        goto CPyL7;
    }
    CPyModule_typing = cpy_r_r22;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r22);
    return 1;
CPyL7: ;
    cpy_r_r23 = 2;
    return cpy_r_r23;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_mypyc_fib = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_numpy___typing = Py_None;
    CPyModule_typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[24];
const char * const CPyLit_Str[] = {
    "\t\005int64\005array\005dtype\006linalg\fmatrix_power\bbuiltins\005numpy\002np\fmypyc_fib.py",
    "\005\b<module>\aNDArray\fnumpy.typing\004cast\006typing",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0021\0000",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {5, 1, 5, 3, 9, 9, 10, 1, 20, 1, 13, 1, 15};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_mypyc_fib_internal = NULL;
CPyModule *CPyModule_mypyc_fib;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_numpy___typing;
CPyModule *CPyModule_typing;
CPyTagged CPyDef_fib_mypyc(CPyTagged cpy_r_n);
PyObject *CPyPy_fib_mypyc(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef_fib_np_mypyc(CPyTagged cpy_r_n);
PyObject *CPyPy_fib_np_mypyc(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
