def bfs(g):
    visited = [0 for i in range(n)]
    q = []
    s = 4                                        # sourse could be any node
    visited[s-1] = 1 
    print(s)
    q.append(s-1)
    while len(q):
        curr = q.pop(0)
        for i in range(n):
            if g[curr][i] == 1 and visited[i] != 1:
                print(i+1)
                visited[i] = 1
                q.append(i)
        if len(q) == 0 :
            for i in range(n):
                if visited[i] == 0 :
                    q.append(i)
                    visited[i] = 1 
                    print(i+1)
                    break

def dfs(g):
    pass

g = [
    [0, 1, 1, 0, 0, 0, 0, 0, 0, 0],  # Node 0
    [1, 0, 1, 0, 0, 0, 0, 0, 0, 0],  # Node 1
    [1, 1, 0, 0, 0, 0, 0, 0, 0, 0],  # Node 2
    [0, 0, 0, 0, 1, 1, 0, 0, 0, 0],  # Node 3
    [0, 0, 0, 1, 0, 1, 0, 0, 0, 0],  # Node 4
    [0, 0, 0, 1, 1, 0, 0, 0, 0, 0],  # Node 5
    [0, 0, 0, 0, 0, 0, 0, 1, 1, 1],  # Node 6
    [0, 0, 0, 0, 0, 0, 1, 0, 1, 1],  # Node 7
    [0, 0, 0, 0, 0, 0, 1, 1, 0, 1],  # Node 8
    [0, 0, 0, 0, 0, 0, 1, 1, 1, 0],  # Node 9
]

n = len(g)                                             # number of nodes

bfs(g)