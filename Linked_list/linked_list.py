

class Node:
    def __init__(self,data=None):
        self.data=data
        self.next=None

class linkedList:
    def __init__(self):
        self.head=Node()
    
    def insert(self,data):
        self.new_node=Node(data)
        if self.head.next == None:
            self.head.next=self.new_node
        else :
            node=self.head.next
            while node.next !=None:
                node=node.next
            node.next=self.new_node

    def display(self):
        node=self.head.next
        while node.next !=None:
            print(node.data)
            node=node.next
        print(node.data)

    def delete(self,data):
        node =self.head.next
        #delete first node 
        if node.data ==data:
            next=node.next
            self.head.next=next
            del node
        else:
            prev_node=self.head
            while node.data !=data:
                node = node.next
                prev_node=prev_node.next
            prev_node.next=node.next
            del node
        
    def display_using_Rec(self,head):
        if (head.next==None):
            return 
        print(head.next.data)
        self.display_using_Rec(head.next)
    
