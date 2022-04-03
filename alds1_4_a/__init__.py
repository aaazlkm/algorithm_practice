from math import floor
import time

# def search_by_binary(S, key):
#     # print(S)
#     # print(key)
#
#     if len(S) == 1:
#         return S[0] == key
#     else:
#         centerIndex = ceil(len(S)/2) - 1
#         if key <= S[centerIndex]:
#             return search_by_binary(S[0:centerIndex + 1], key)
#         else:
#             return search_by_binary(S[centerIndex + 1:len(S)], key)


def search_by_binary(S, key):
    left = 0
    right = len(S)

    while left < right:
        middle = floor((right + left) / 2)
        if key == S[middle]:
            return True
        elif key < S[middle]:
            right = middle
        else:
            left = middle + 1
    return False

def main():
    from sys import stdin
    input = stdin.readline
    n = input()
    S = []
    for it in input().split():
        S.append(int(it))
    q = input()
    C = 0
    for t in input().split():
        if search_by_binary(S, int(t)):
            C += 1
    print(C)


if __name__ == '__main__':
    main()
