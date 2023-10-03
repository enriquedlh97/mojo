#include <pybind11/pybind11.h>

namespace py = pybind11;

int fibm(int n) {
    return (n < 2) ? n : fibm(n - 1) + fibm(n - 2);
}

PYBIND11_MODULE(fibm_module, m) {
    m.def("fibm", &fibm, "Calculate Fibonacci number using C++");
}
