class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, val):
        self.items.insert(0, val)

    def dequeue(self):
        return self.items.pop()

    def is_empty(self):
        return self.items == []

    def display(self):
        print(self.items)
