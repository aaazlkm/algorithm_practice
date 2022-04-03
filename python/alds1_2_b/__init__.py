
# https://qiita.com/knakajima3027/items/b871631b8997a6d67223

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    count = 0

    for i in range(0, n):
        minj = i
        isExchanged = False
        for j in range(i, n):
            if a[j] < a[minj]:
                isExchanged = True
                minj = j
        if isExchanged:
            count = count + 1
        a[i], a[minj] = a[minj], a[i]

    print(' '.join([str(e) for e in a]))
    print(count)
