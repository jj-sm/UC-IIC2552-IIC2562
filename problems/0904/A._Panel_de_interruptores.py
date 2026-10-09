# A. Panel de interruptores

import sys

input = sys.stdin.readline

def print_lexi(c: list[str], n: int, position: int) -> None:
    if position == n:
        print(''.join(c))
        return

    c[position] = '0'
    print_lexi(c, n, position + 1)

    c[position] = '1'
    print_lexi(c, n, position + 1)


def main():
    n = int(input())
    c = ['0'] * n
    print_lexi(c, n, 0)


if __name__ == "__main__":
    main()