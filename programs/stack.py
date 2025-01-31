class Queue:
    def __init__(self,n):
        self.q = []
        self.n = n
    def enqueue(self,x):
        if (len(self.q) == self.n):
            return "Queue is Full"
        self.q.append(x)
        return True
    def dequeue(self):
        if (not len(self.q)):
            return "Queue is empty"
        return self.q.pop(0)
q = Queue(2)
res = q.enqueue(3)
print(res)
res = q.enqueue(4)
print(res)
res = q.enqueue(5)
print(res)
res = q.dequeue()
print(res)
res = q.dequeue()
print(res)
res = q.dequeue()
print(res)
