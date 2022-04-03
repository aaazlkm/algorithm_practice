
def main():
    n = input()
    S = list(map(int, input().split()))
    q = input()
    T = list(map(int, input().split()))

    sMap = {}
    for s in S:
        if s in sMap:
            sMap[s] += 1
        else:
            sMap[s] = 1

    C = 0
    for t in T:
        if t in sMap:
            C += 1
    print(C)



if __name__ == '__main__':
    main()
