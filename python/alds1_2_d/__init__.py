
# https://qiita.com/knakajima3027/items/b871631b8997a6d67223

cnt = 0


def insertion_sort(a, n, g):
    for i in range(g, n):
        v = a[i]
        j = i - g
        # print(f"====={i}=====")
        # print("before: " + ' '.join([str(e) for e in a]))
        while j >= 0 and a[j] > v:
            global cnt
            a[j + g] = a[j]
            j = j - g
            cnt = cnt + 1
        a[j + g] = v
        # print("after: " + ' '.join([str(e) for e in a]))


def shell_sort(a, n):
    step = 5
    G = []
    i = 0
    value = 1
    flag = True
    while flag:
        value = value + (step ** i if i != 0 else 0)
        if value > n:
            flag = False
        else:
            G.append(value)
            i = i + 1
    G.reverse()
    for i in range(0, len(G)):
        insertion_sort(a, n, G[i])
    return [a, G]


n = int(input())
a = list()
for _ in range(0, n):
    a.append(int(input()))

result, G = shell_sort(a.copy(), n)
print(len(G))
print(' '.join([str(e) for e in G]))
print(f"{cnt}")
for e in result:
    print(str(e))
