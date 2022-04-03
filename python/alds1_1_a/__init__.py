
# https://qiita.com/knakajima3027/items/b871631b8997a6d67223


def answer():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(0, n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = v
        print(' '.join([str(e) for e in a]))


if __name__ == '__main__':
    answer()
