from time import time
from fibm_module import fibm

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