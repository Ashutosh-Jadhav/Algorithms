class Linked_list:
    def __init__(self,val,p=None):
        self.val = val
        self.p = p

    def add_node(self,val):
        current = self
        while(current.p):
            current = current.p
        current.p = Linked_list(val)
    
    def print_ll(self):
        current = self
        while(current.p):
            print(current.val,end = (" "))
            current = current.p
        print(current.val)

n1 = Linked_list(5)
n1.add_node(10)
n1.add_node(11)
n1.add_node(12)
n1.add_node(13)
n1.add_node(14)
n1.add_node(15)
n1.add_node(16)
n1.add_node(17)
n1.add_node(18)
n1.print_ll()
