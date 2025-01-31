class Tree:
    def __init__(self,val,l= None,r = None):
        self.val = val
        self.l = l
        self.r = r
        
    def add_right_child(self,x):
        if (self.r):
            self.r = self.r.r
        self.r = Tree(x)

    def add_left_child(self,x):
        self.l = Tree(x)
    
    def pre_order(self):
        print(self.val)
        if self.l:
            self.l.pre_order()
        if self.r:
            self.r.pre_order()

n1 = Tree(2)
n1.add_left_child(3)
n1.add_right_child(4)
n1.pre_order()
n1.add_right_child(5)
n1.pre_order()
