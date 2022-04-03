# https://qiita.com/knakajima3027/items/b871631b8997a6d67223

from sys import stdin


def print_hi():
    lines = read_inputs()
    min_start = 10 ** 10
    max_end_j = 0
    max_profit = - 10 ** 10
    for i, value in enumerate(lines):
        if value < min_start:
            min_start = value
        else:
            continue

        if i < max_end_j:
            profit = lines[max_end_j] - min_start
            if max_profit < profit:
                max_profit = profit
            continue
        else:
            max_end_j = i + 1

        for j in range(i + 1, len(lines)):
            profit = lines[j] - min_start
            if max_profit < profit:
                max_profit = profit
            if lines[max_end_j] < lines[j]:
                max_end_j = j
    print(max_profit)


def read_inputs():
    n = int(stdin.readline().rstrip())
    lines = [int(stdin.readline().rstrip()) for _ in range(n)]
    return lines


def answer():
    n = int(input())
    maxV = - 10 ** 10  # R[1] - R[0]でもいい
    minV = None
    for j in range(0, n):
        r = int(input())
        if j == 0:
            minV = r
            continue
        maxV = max(maxV, r - minV)
        minV = min(minV, r)
    print(maxV)


if __name__ == '__main__':
    answer()
