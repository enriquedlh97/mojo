import numpy as np
from numpy.typing import NDArray
from typing import cast


def fib_nuitka(n: int) -> int:
    return n if n < 2 else fib_nuitka(n - 1) + fib_nuitka(n - 2)

def fib_np_nuitka(n: int) -> int:
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
            dtype=np.int64
        )

        result: NDArray = np.linalg.matrix_power(matrix, n - 1)

        return int(result[0, 0])