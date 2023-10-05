from time import time
from fibm_module import fibm as fib_pybind
import numpy as np
from numpy.typing import NDArray
from mypyc_fib import fib_mypyc, fib_np_mypyc
from nuitka_fib import fib_nuitka#, fib_np_nuitka

def fib_np(n: int) -> int:
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        matrix: NDArray = np.array(
            [
                [1, 1],
                [1, 0]
            ],
            dtype=object
        )

        result: NDArray = np.linalg.matrix_power(matrix, n - 1)

        return result[0, 0]
    

def fib_python(n):
    return n if n < 2 else fib_python(n - 1) + fib_python(n - 2)


def run_python_benchmark(function_name, n):
    t0 = time()
    ans = function_name(n)
    t1 = time()
    return f'Computed fib({n}) = {ans} in\t{round(t1 - t0, 4)} seconds.'


def main():
    n = 40
    print(f"NUMPY MYPYC: {run_python_benchmark(fib_np_mypyc, n)}")
    print(f"      NUMPY: {run_python_benchmark(fib_np, n)}")
    print(f"     PYBIND: {run_python_benchmark(fib_pybind, n)}")
    print(f"      MYPYC: {run_python_benchmark(fib_mypyc, n)}")
    print(f"      NUITKA: {run_python_benchmark(fib_nuitka, n)}")
    print(f"     PYTHON: {run_python_benchmark(fib_python, n)}")


if __name__ == "__main__":
    main()