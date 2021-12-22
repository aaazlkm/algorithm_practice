
# https://qiita.com/knakajima3027/items/b871631b8997a6d67223

def bubble_sort(a, n):
    flag = True
    while flag:
        flag = False
        for i in range(n - 1, 0, -1):
            if int(a[i-1][1]) > int(a[i][1]):
                a[i], a[i-1] = a[i-1], a[i]
                flag = True
    return a


def selection_sort(a, n):
    for i in range(0, n):
        minJ = i
        for j in range(i, n):
            if int(a[minJ][1]) > int(a[j][1]):
                minJ = j
        a[minJ], a[i] = a[i], a[minJ]
    return a


def check_stable(a, sortedA):
    for num in range(1, 10):
        aNums = list(filter(lambda e: e[1] == str(num), a))
        sortedANums = list(filter(lambda e: e[1] == str(num), sortedA))
        if aNums != sortedANums:
            return False
    return True


n = int(input())
a = list(map(str, input().split()))

bubbleResult = bubble_sort(a.copy(), n)
print(' '.join([str(e) for e in bubbleResult]))
print("Stable" if check_stable(a, bubbleResult) else "Not stable")

selectionResult = selection_sort(a.copy(), n)
print(' '.join([str(e) for e in selectionResult]))
print("Stable" if check_stable(a, selectionResult) else "Not stable")
