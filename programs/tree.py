class Tree:
    def __init__(self,val,l= None,r = None):
        self.val = val
        self.l = l
        self.r = r
        
    def add_right_child(self,x):
        if not self.r:
            self.r = Tree(x)
            return
        current = self.r
        while (current.r and current.l):
            current = current.r
        if (current.r):
            current.l = Tree(x)
        else:
            current.r = Tree(x)

    def add_left_child(self,x):
        current = self
        # while
        self.l = Tree(x)
    
    def pre_order(self):
        print(self.val,end=" ")
        if self.l:
            self.l.pre_order()
        if self.r:
            self.r.pre_order()
        

n1 = Tree(2)
n1.add_left_child(3)
n1.add_right_child(4)
n1.add_right_child(5)
n1.add_right_child(6)
n1.add_right_child(7)
n1.add_right_child(8)
n1.pre_order()
print(" ")
