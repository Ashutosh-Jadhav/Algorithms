# return true if given input is stack sequence 
l = [4,3,1,5,2]     # input     [1,2,3,4,5]
s = []              # stack
j = 0
for i in range(1,len(l)+1):
    s.append(i)
    while s and s[-1] == l[j] :
        s.pop()
        j= j+1

if not s:
    print(True)
else :
    print(False)