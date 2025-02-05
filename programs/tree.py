import random
class Node:
    def __init__(self,val,l=None,r=None,p=None):
        self.val = val
        self.l = l
        self.r = r
        self.p = p

class Tree:
    def __init__(self):
        self.root = None
        
    def add_child(self,x):
        a = random.randrange(10)
        new_node = Node(x)
        if not self.root:
            self.root = new_node
            return
        current = self.root
        while (current.r and current.l):
            if a%2 == 0 :
                current = current.r
            else:
                current = current.l
        if (current.r):
            current.l = new_node
            new_node.p = current
        else:
            current.r = new_node
            new_node.p = current
    
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
n1.add_child(3)
n1.add_child(4)
n1.add_child(5)
n1.add_child(6)
n1.add_child(7)
n1.add_child(8)
n1.pre_order()
print()