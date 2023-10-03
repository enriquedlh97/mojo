from time import now


def fibm(n):
    return n if n < 2 else fibm(n - 1) + fibm(n - 2)


def main():
    let t0 = now()
    let ans = fibm(40)
    let t1 = now()

    ans.print()
    print("\n")
    print("Computed fibm(40)", (t1 - t0) / 1e9, "seconds")

# 102334155
# Computed fibm(40) 4.2934318319999996 seconds