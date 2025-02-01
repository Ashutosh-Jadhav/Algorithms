class Node:
    def __init__(self,val,next = None):
        self.val = val
        self.next = next

class Linked_list:
    def __init__(self):
        self.head = None

    def add_node(self,val):
        new_node = Node(val)
        if (not self.head):
            self.head = new_node
            return
        current = self.head
        while(current.next):
            current = current.next
        current.next = new_node
    
    def print_ll(self):
        current = self.head
        while(current):
            print(current.val,end = (" "))
            current = current.next
        print()

    def search_ll(self,t):
        if (not self.head):
            return -1
        current = self.head
        while(current):
            if (current.val == t):
                return current
            current = current.next
        return -1

l1 = Linked_list()
l1.add_node(10)
l1.add_node(11)
l1.add_node(12)
l1.add_node(13)
l1.add_node(14)
l1.add_node(15)
l1.add_node(16)
l1.add_node(17)
l1.add_node(18)
l1.print_ll()
l2 = Linked_list()
pos = l2.search_ll(8)
print(pos)
