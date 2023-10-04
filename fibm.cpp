#include <pybind11/pybind11.h>

namespace py = pybind11;

int fibm(int n) {
    return (n < 2) ? n : fibm(n - 1) + fibm(n - 2);
}

int fibonacci_matrix(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        long long int a = 1, b = 1, c = 1, d = 0;
        long long int temp1, temp2;

        for (int i = 2; i <= n; i++) {
            temp1 = a * c + b * d;
            temp2 = b * c + d * (a + b);
            a = temp1;
            b = temp2;
        }

        return b;
    }
}

// Wrapper function to call the fibonacci_matrix function with an integer input
int fibonacci_matrix_wrapper_2(int n) {
    return fibonacci_matrix(n);
}

PYBIND11_MODULE(fibm_module_extended, m) {
    m.def("fibm", &fibm, "Calculate Fibonacci number using C++");
    m.def("fibonacci_matrix", &fibonacci_matrix_wrapper_2, "Calculate Fibonacci number using matrix exponentiation");
}








// Wrapper function to call the fibonacci_matrix function with an integer input
int fibonacci_matrix_wrapper(int n) {
    return fibonacci_matrix(n);
}

PYBIND11_MODULE(fibm_module, m) {
    m.def("fibm", &fibm, "Calculate Fibonacci number using C++");
    m.def("fibonacci_matrix", &fibonacci_matrix_wrapper, "Calculate Fibonacci number using matrix exponentiation");
}
