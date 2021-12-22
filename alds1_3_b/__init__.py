# https://qiita.com/knakajima3027/items/b871631b8997a6d67223

def main():
    n, q = list(map(int, input().split()))
    lines = [list(map(str, input().split())) for _ in range(0, n)]
    queue = Queue(lines)

    elapsedTime = 0
    while not queue.is_empty():
        line = queue.dequeue()
        name = line[0]
        times = int(line[1])
        if times > q:
            elapsedTime += q
            queue.enqueue([name, times - q])
        else:
            elapsedTime += times
            print(f"{name} {elapsedTime}")


class Queue:
    list = []

    def __init__(self, list):
        self.list = list

    def enqueue(self, val):
        self.list.append(val)

    def dequeue(self):
        if self.is_empty():
            pass
        val = self.list[0]
        del (self.list[0])
        return val

    def is_empty(self):
        return len(self.list) == 0


if __name__ == '__main__':
    main()


