# very imp algo for cp
# next largest towards right
a = [4,6,7,2,8,90,12]
b = [len(a) for i in range(len(a))]
s = []           # This is a stack
for i in range(len(a)):
    while(s and a[s[-1]] < a[i]):
        b[s[-1]] = i
        s.pop()
    s.append(i)
print(b)

# next largest towards left
s = []
b = [len(a) for i in range(len(a))]
for i in range(len(a)):
    while(s and a[s[-1]] < a[len(a) - i -1]):
        b[s[-1]] = len(a) -i-1
        s.pop()
    s.append(len(a) - i - 1)
print(b)