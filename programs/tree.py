class Node:
    def __init__(self,val,l=None,r=None,p=None):
        self.val = val
        self.l = l
        self.r = r
        self.p = p

class Tree:
    def __init__(self):
        self.root = None
        
    def add_right_child(self,x):
        new_node = Node(x)
        if not self.root:
            self.root = new_node
            return
        current = self.root
        while (current.r and current.l):
            current = current.r
        if (current.r):
            current.l = new_node
        else:
            current.r = new_node

    def add_left_child(self,x):
        new_node = Node(x)
        if not self.root:
            self.root = new_node
            return
        current = self.root
        while(current.l):
            current = current.l
        current.l = new_node
    
    def pre_order(self,n = None):
        if not n:
            n = self.root
        if not n:
            return
        print(n.val,end=" ")
        if n.l:
            self.pre_order(n.l)
        if n.r:
            self.pre_order(n.r)
        

n1 = Tree()
n1.add_left_child(3)
n1.add_right_child(4)
n1.add_right_child(5)
n1.add_right_child(6)
n1.add_right_child(7)
n1.add_right_child(8)
n1.pre_order()
print(" ")
