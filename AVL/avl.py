class Node:
    def __init__(self):
        self.data = None
        self.left = None
        self.right = None


class Avl:
    def __init__(self) -> None:
        self.root = None

    def _insert(self, root, node):
        if root == None:
            root = node

        elif root.data > node.data:
            root.left = self._insert(root.left, node)
        else:
            root.right = self._insert(root.right, node)
        return root

    def insert(self, data):
        node = Node()
        node.data = data
        self.root = self._insert(self.root, node)

    def _search(self, root, data):
        if root == None:
            raise "tree is empty"
        elif root.data == data:
            return root
        elif root.data > data:
            return self._search(root.left, data)
        else:
            return self._search(root.right, data)

    def search(self, data):
        node = self._search(self.root, data)
        return node.data

    def _height(self, node):
        if node == None:
            return -1
        else:
            return max(self._height(node.left), self._height(node.right)) + 1

    def height(self, data):
        node = self._search(self.root, data)
        hegiht = self._height(node)
        return hegiht


s = Avl()
s.insert(6)

s.insert(7)
s.insert(8)
s.insert(2)
s.insert(3)
s.insert(4)
s.insert(5)

print(s.height(6))
