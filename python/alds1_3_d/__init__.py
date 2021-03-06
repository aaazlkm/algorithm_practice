# https://qiita.com/knakajima3027/items/b871631b8997a6d67223
#
# def calculate_area_to_same_depth(grounds, fromIndex):
#     allArea = 0
#     depth = 0
#     depthToIndexs = {}
#
#     for i in range(fromIndex, len(grounds)):
#         nowGround = grounds[i]
#         prevDepth = depth
#
#         if nowGround == "\\":
#             depth -= 1
#         elif nowGround == "/":
#             depth += 1
#         elif nowGround == "_":
#             pass
#
#         if not (depth in depthToIndexs):
#             depthToIndexs[depth] = []
#         depthToIndexs[depth] = depthToIndexs[depth] + [i]
#
#         # 台形の計算をしてる
#         allArea += ((abs(prevDepth) + abs(depth)) * 1 / 2)
#
#         if i != fromIndex and depth == 0:
#             return [0, i, int(allArea)]
#
#     # print(depthToIndexs)
#     multiIndexDepths = list(filter(lambda x: len(depthToIndexs[x]) > 1, [*depthToIndexs]))
#     if len(multiIndexDepths) == 0:
#         return [None, None, None]
#
#     multiIndexDepths.sort()
#     # print(multiIndexDepths)
#     mimDepth = multiIndexDepths[-1]
#     if mimDepth != 0:
#         # print(depthToIndexs[mimDepth])
#         return [1, depthToIndexs[mimDepth][0], None]
#     else:
#         return [None, None, None]
#
#
# def main():
#     from sys import stdin
#     readline = stdin.readline
#     grounds = str(readline()).strip()
#
#     allAreas = []
#     i = 0
#     while i < len(grounds):
#         ground = grounds[i]
#         if ground == "\\":
#             # 毎回探すのではなく、存在しない場合は存在する位置に移動するようにする
#             type, endIndex, area = calculate_area_to_same_depth(grounds, i)
#             if type == 0:
#                 if endIndex is not None and area is not None:
#                     allAreas.append(area)
#                     i = endIndex + 1
#                     continue
#             elif type == 1:
#                 print(f"endIndex: {endIndex}, i: {i}")
#                 i = endIndex + 1
#                 continue
#         elif ground == "/":
#             pass
#         elif ground == "_":
#             pass
#         i += 1
#
#     print(sum(allAreas))
#     print(' '.join([str(len(allAreas))] + list(map(lambda x: str(x), allAreas))))

def main():
    from sys import stdin
    readline = stdin.readline
    grounds = str(readline()).strip()
    allAreaStack = []
    areasStack = []
    allArea = 0

    for i in range(0, len(grounds)):
        if grounds[i] == "\\":
            allAreaStack.append(i)
        elif grounds[i] == "/":
            if len(allAreaStack) != 0:
                j = allAreaStack.pop()
                area = i - j
                allArea += area
                while len(areasStack) != 0 and areasStack[-1][0] > j:
                    area += areasStack[-1][1]
                    areasStack.pop()
                areasStack.append((j, area))

    print(allArea)
    print(' '.join([str(len(areasStack))] + list(map(lambda x: str(x[1]), areasStack))))



if __name__ == '__main__':
    main()
