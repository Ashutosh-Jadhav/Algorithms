# next smallest towards right
a = [3,2,6,8,9,2,45,63,0]
b = [len(a) for i in range(len(a))]
s = []

for i in range(len(a)):
    while s and a[s[-1]] > a[i]:
        b[s[-1]] = i
        s.pop()
    s.append(i)

print(b)