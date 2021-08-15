from queue import Queue


class Node:
    def __init__(self):
        self.data = None
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None
        self.queuy = Queue()

    def insert_node_rescusrion(self, root, node):
        if root == None:
            root = node
        elif node.data < root.data:
            root.left = self.insert_node_rescusrion(root.left, node)
        else:
            root.right = self.insert_node_rescusrion(root.right, node)

        return root

    def insert_node(self, node):
        if self.root == None:
            self.root = node
        else:
            temp = self.root
            while temp != None:
                if node.data <= temp.data and temp.left == None:
                    temp.left = node
                    break
                elif node.data < temp.data:
                    temp = temp.left
                elif node.data > temp.data and temp.right == None:
                    temp.right = node
                    break
                else:
                    temp = temp.right

    def insert(self, data):
        """ insert node """
        node = Node()
        node.data = data
        self.insert_node(node)

    def insert_recursion(self, data):
        """ insert node using recusrion"""
        node = Node()
        node.data = data
        self.root = self.insert_node_rescusrion(self.root, node)

    def max(self, root):
        """ find max element in the tree"""
        if root == None:
            raise "no nodes in the tree"
        while root.right != None:
            root = root.right
        return root

    def find_max(self):
        max = self.max(self.root)
        return max.data

    def min(self, root):
        if root == None:
            raise "no nodes in the tree"
        while root.right != None:
            root = root.right
        return root

    def find_min(self):
        min = self.min(self.root)
        return min.data

    def max_recursion(self, root):
        if root == None:
            raise "no nodes in the tree"
        elif root.right == None:
            return root.data
        else:
            return self.max_recursion(root.right)

    def find_max_recursion(self):
        """ find max element in the tree using recursion"""
        max = self.max_recursion(self.root)
        return max

    def recusrive_search(self, root, data):
        if root == None:
            return False, root
        elif root.data == data:
            return True, root
        elif root.data < data:
            return self.recusrive_search(root.right, data)
        else:
            return self.recusrive_search(root.left, data)

    def search(self, data):
        """ search for element in the tree (return bool)"""
        result = self.recusrive_search(self.root, data)
        return result[0]

    def recursive_height(self, node):
        if node == None:
            return -1
        else:
            return max(self.height(node.left), self.height(node.right)) + 1

    def height(self, node):
        if node == None:
            return -1
        counter_right = 0
        counter_left = 0
        temp1 = node
        temp2 = node
        while temp1.right != None:
            temp1 = temp1.right
            counter_right += 1

        while temp2.left != None:
            temp2 = temp2.left
            counter_left += 1
        return max(counter_left, counter_right)

    def depth(self, node):
        if self.root == node:
            return 0
        temp = self.root
        counter = 0
        while temp != node:
            if temp.data < node.data:
                temp = temp.right
                counter += 1
            elif temp.data > node.data:
                temp = temp.left
                counter += 1
        return counter

    def find_height(self, data):
        """find heigh of a node,(hegiht is number of edges in the longest path
        from a node to a leaf node)
        """
        find_node = self.recusrive_search(self.root, data)[1]
        height = self.recursive_height(find_node)
        if height == -1:
            return "node doesnot exist"
        return height

    def tree_height(self):
        """ find the heigt of the tree"""
        height = self.height(self.root, self.root.data)
        return height

    def find_depth(self, data):
        """ depth of a node is the number of edges from the root to the node"""
        find_node = self.recusrive_search(self.root, data)[1]
        depth = self.depth(find_node)
        return depth

    def _delete(self, root, data):
        if root == None:
            return root  # note found
        elif root.data > data:
            root.left = self._delete(root.left, data)
        elif root.data < data:
            root.right = self._delete(root.right, data)
        else:
            if root.left == None:  # only right child or no childern(leaf node)
                temp = root
                root = root.right
                del temp
            elif root.right == None:  # only left child
                temp = root
                root = root.left
                del temp
            else:
                min = self.min(root)
                root.data = min.data
                self._delete(root.right, min.data)
        return root

    def delete_node(self, data):
        self.root = self._delete(self.root, data)

    def display_bft(self):  # breadth first traversal
        root = self.root

        if root == None:
            print("Tree is empty")
            return

        self.queuy.put(root)
        while not self.queuy.empty():
            temp = self.queuy.get()
            print(temp.data)
            if temp.left != None:
                self.queuy.put(temp.left)
            if temp.right != None:
                self.queuy.put(temp.right)

    def _inorder(self, root):
        if root == None:
            return
        self._inorder(root.left)
        print(root.data)
        self._inorder(root.right)

    def _preorder(self, root):
        if root == None:
            return
        print(root.data)
        self._preorder(root.left)
        self._preorder(root.right)

    def _postorder(self, root):
        if root == None:
            return
        self._postorder(root.left)
        self._postorder(root.right)
        print(root.data)

    def dfs_perorder(self):  # depth first search traversal <root><left><right>
        self._preorder(self.root)

    def dfs_inorder(self):  # depth first search traversal <left><root><right>
        self._inorder(self.root)

    def dfs_postorder(self):  # depth first search traversal <left><right><root>
        self._postorder(self.root)


b = BST()
b.insert(12)

b.insert_recursion(20)
b.insert_recursion(27)
b.insert_recursion(17)
b.insert_recursion(13)
b.insert_recursion(18)
