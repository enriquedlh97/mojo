from time import now


fn fibf(n: Int) -> Int:
    return n if n < 2 else fibf(n - 1) + fibf(n - 2)


def main():
    let t0 = now()
    let ans = fibf(40)
    let t1 = now()
    print("Computed fibf(40)", ans, (t1 - t0) / 1e9, "seconds")