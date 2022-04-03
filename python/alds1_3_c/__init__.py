# https://qiita.com/knakajima3027/items/b871631b8997a6d67223

class Node(object):
    def __init__(self, value, prev=None, next=None):
        self.value = value
        self.prev = prev
        self.next = next


class List(object):
    def __init__(self):
        self.firstNode = self.lastNode = None

    def insert(self, x):
        if self.firstNode is None:
            node = Node(x, prev=None, next=None)
            self.firstNode = self.lastNode = node
        else:
            node = Node(x, prev=None, next=self.firstNode)
            self.firstNode.prev = node
            self.firstNode = node

    def delete(self, x):
        node = self.firstNode
        while node is not None:
            if node.value == x:
                if node.prev is None and node.next is None:
                    self.firstNode = None
                    self.lastNode = None
                else:
                    if node.prev is None:
                        node.next.prev = None
                        self.firstNode = node.next
                    elif node.next is None:
                        node.prev.next = None
                        self.lastNode = node.prev
                    else:
                        node.prev.next = node.next
                        node.next.prev = node.prev
                break
            node = node.next

    def delete_first(self):
        if self.firstNode is self.lastNode:
            self.firstNode = self.lastNode = None
        else:
            self.firstNode.next.prev = None
            self.firstNode = self.firstNode.next

    def delete_last(self):
        if self.firstNode is self.lastNode:
            self.firstNode = self.lastNode = None
        else:
            self.lastNode.prev.next = None
            self.lastNode = self.lastNode.prev

    def get_content(self):
        result = []
        node = self.firstNode
        while node is not None:
            result.append(node.value)
            node = node.next
        return ' '.join(result)


def main():
    from sys import stdin
    readline = stdin.readline
    n = int(readline())
    listData = List()
    insert = listData.insert
    delete = listData.delete
    delete_first = listData.delete_first
    delete_last = listData.delete_last
    for _ in range(n):
        command = readline()
        if command == "deleteFirst\n":
            delete_first()
        elif command == "deleteLast\n":
            delete_last()
        else:
            operator, value = command.split()
            if operator == "insert":
                insert(value)
            elif operator == "delete":
                delete(value)

    print(listData.get_content())


if __name__ == '__main__':
    main()

#
#     # #
#     # # result = []
#     # # for i in range(0, 2000000):
#     # #     result.append(i)
#     # # print(' '.join([str(e) for e in result]))
#
#     #
#     # test_insert()
#     # test_delete_first()
#     # test_delete_last()
#     # test_delete()
#
#
# def test_insert():
#     list = List()
#     list.insert(1)
#     if not (list.firstNode.value == 1 and list.firstNode.prev is None and list.firstNode.next is None):
#         raise "エラー"
#
#     list.insert(2)
#     if not (list.firstNode.value == 2 and list.firstNode.next.value == 1 and list.firstNode.next.prev.value == 2):
#         raise "エラー"
#
#     print("pass test")
#
#
# def test_delete():
#     list = List()
#     list.insert(1)
#     list.delete(0)
#     if not (list.firstNode.value == 1):
#         raise "エラー"
#
#     list = List()
#     list.insert(1)
#     list.delete(1)
#     if not (list.firstNode is None):
#         raise "エラー"
#
#     list = List()
#     list.insert(2)
#     list.insert(1)
#     list.delete(1)
#     if not (list.firstNode.value == 2 and list.firstNode.prev is None):
#         raise "エラー"
#
#     list = List()
#     list.insert(2)
#     list.insert(1)
#     list.delete(2)
#     if not (list.firstNode.value == 1 and list.firstNode.next is None):
#         raise "エラー"
#
#     list = List()
#     list.insert(3)
#     list.insert(2)
#     list.insert(1)
#     list.delete(2)
#     if not (list.firstNode.value == 1 and list.firstNode.next.value == 3):
#         raise "エラー"
#
#     print("pass delete test")
#
#
# def test_delete_first():
#     list = List()
#     list.insert(1)
#     list.delete_first()
#     if not (list.firstNode is None):
#         raise "エラー"
#
#     list.insert(2)
#     list.insert(1)
#     list.delete_first()
#     if not (list.firstNode.value == 2 and list.firstNode.prev is None):
#         raise "エラー"
#
#     print("pass delete first test")
#
#
# def test_delete_last():
#     list = List()
#     list.insert(1)
#     list.delete_last()
#     if not (list.firstNode is None):
#         raise "エラー"
#
#     list = List()
#     list.insert(2)
#     list.insert(1)
#     list.delete_last()
#     if not (list.firstNode.value == 1 and list.firstNode.next is None):
#         raise "エラー"
#
#     list = List()
#     list.insert(3)
#     list.insert(2)
#     list.insert(1)
#     list.delete_last()
#     if not (list.firstNode.value == 1 and list.firstNode.next.value == 2 and list.firstNode.next.next is None):
#         raise "エラー"
#
#     print("pass delete last test")
#
