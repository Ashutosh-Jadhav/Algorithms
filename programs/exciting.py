arr1 = [[1,3,1,1,2],[1,5,1,2,1],[4,2,1,3,1],[2,1,5,1,1],[1,1,1,1,1]]
temp = [[1,3,1,1,2],[1,5,1,2,1],[4,2,1,3,1],[2,1,5,1,1],[1,1,1,1,1]]
print(arr1 is temp)
def f(lis):
    for i in range(len(lis)):
        for l in range(1,len(lis)-1):
            lis[l][0] =  temp[l][0]+min(lis[l+1][0] , lis[l-1][0] , lis[l][1]) 


        lis[0][len(lis[0])-1] = min(lis[1][len(lis[0])-1] , lis[0][len(lis[0])-2])
        for m in range(1,len(lis[0])-1): 
            lis[0][m] = temp[0][m]+ min(lis[1][m] , lis[0][m-1] , lis[0][m+1]) 

        lis[len(lis)-1][0] = temp[len(lis)-1][0] + min(lis[len(lis)-2][0] , lis[len(lis)-1][1]) 
        for j in range(1,len(lis)-1):
            for k in range(1,len(lis[0])-1):
                lis[j][k] = temp[j][k] + min(lis[j-1][k] , lis[j+1][k] , lis[j][k+1] , lis[j][k-1]) 

        for l in range(1,len(lis)-1):
            lis[l][len(lis[0])-1] = temp[l][len(lis[0])-1] + min(lis[l-1][len(lis[0])-1],lis[l+1][len(lis[0])-1],lis[l][len(lis[0])-2])  

        for l in range(1,len(lis[0])-1):
            lis[len(lis)-1][l] = temp[len(lis)-1][l] + min(lis[len(lis)-2][l] , lis[len(lis)-1][l-1] , lis[len(lis)-1][l+1]) 

        lis[len(lis)-1][len(lis[0])-1] = temp[len(lis)-1][len(lis[0])-1] + min(lis[len(lis)-2][len(lis[0])-1] , lis[len(lis)-1][len(lis[0])-2])  

for i in range(len(arr1)):
    for j in range(len(arr1[0])):
        print(arr1[i][j],end = " ")
    print()
f(arr1)

for i in range(len(arr1)):
    for j in range(len(arr1[0])):
        print(arr1[i][j],end = " ")
    print()

