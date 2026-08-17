

def potencia(a: int, b: int, mod: int) -> int:
    ans: int = 1

    for _ in range(b):
        ans = ans * (a % mod) % mod

    return ans