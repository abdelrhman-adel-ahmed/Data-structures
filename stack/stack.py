class Stack:
    def __init__(self):
        self.items = []

    def push(self, val):
        self.items.insert(0, val)

    def pop(self):
        return self.items.pop(0)

    def is_empty(self):
        return self.items == []

    def display(self):
        print(self.items)
