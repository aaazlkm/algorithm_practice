# https://qiita.com/knakajima3027/items/b871631b8997a6d67223

def main():
    a = list(map(str, input().split()))
    stack = Stack(a)
    calc(stack)
    print(stack.pop())


def calc(stack):
    val = stack.pop()
    if val in ["+", "-", "*"]:
        calc(stack)
        right = stack.pop()
        calc(stack)
        left = stack.pop()
        if val == "+":
            stack.push(left + right)
        elif val == "-":
            stack.push(left - right)
        elif val == "*":
            stack.push(left * right)
        else:
            pass
    else:
        stack.push(int(val))


class Stack:
    list = []

    def __init__(self, list):
        self.list = list

    def push(self, val):
        self.list.append(val)

    def pop(self):
        return self.list.pop()

    def is_empty(self):
        return len(self.list) == 0


if __name__ == '__main__':
    main()


