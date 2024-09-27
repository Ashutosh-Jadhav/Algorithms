t = int(input())
while (t>0):
    t = t- 1
    res = 0
    n,k = input().split()
    for i in range(len(n)):
        if n[i] == k :
            res = res + 1
    print(res)