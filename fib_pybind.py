from time import time
from fibm_module import fibm, fibonacci_matrix
import numpy as np
from numpy.typing import NDArray


def fib_np(n: int) -> int:
    if n <= 0:
        return 0
    elif n == 1:
        return
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

    
def run_python_benchmark_numpy():
    t0 = time()
    ans = fib_np(40)
    t1 = time()
    print(f'NUMPY: Computed fib(40) = {ans} in {t1 - t0} seconds.')


def run_python_benchmark_pybind_matrix():
    t0 = time()
    ans = fibonacci_matrix(40)
    t1 = time()
    print(f'MATRIX PYBIND: Computed fib(40) = {ans} in {t1 - t0} seconds.')

def run_python_benchmark_pybind():
    t0 = time()
    ans = fibm(40)
    t1 = time()
    print(f'PYBIND: Computed fib(40) = {ans} in {t1 - t0} seconds.')



def fib(n):
    return n if n < 2 else fib(n - 1) + fib(n - 2)


def run_python_benchmark():
    t0 = time()
    ans = fib(40)
    t1 = time()
    print(f'PYTHON: Computed fib(40) = {ans} in {t1 - t0} seconds.')

run_python_benchmark_pybind()
# Computed fib(40) = 102334155 in 21.669286727905273 seconds.
run_python_benchmark()

run_python_benchmark_numpy()

run_python_benchmark_pybind_matrix()