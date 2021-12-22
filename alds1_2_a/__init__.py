
# https://qiita.com/knakajima3027/items/b871631b8997a6d67223


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    flag = True
    count = 0
    while flag:
        flag = False
        for i in range(n - 1, 0, -1):
            if a[i] < a[i - 1]:
                a[i], a[i - 1] = a[i - 1], a[i]
                flag = True
                count += 1

    print(' '.join([str(e) for e in a]))
    print(count)
