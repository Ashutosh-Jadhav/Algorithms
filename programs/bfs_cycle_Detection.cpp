class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> visited(V,0) ;
        int u,v,temp;
        vector<int> p(V,-1);
        queue<int> q ;
        q.push(0); visited[0] = 1 ; p[0] = 0;
        while(!q.empty()) {
            u = q.front(); q.pop();
            for (int i = 0 ; i < edges.size() ; i++) {
                if (edges[i][0] == u) {
                    v = edges[i][1];
                    if (visited[v] == 0) {
                        p[v] = u ;
                        q.push(v) ;
                        visited[v] = 1 ;
                    }
                    else {
                        if (p[u] != v) return true;
                    }
                    
                }
                if (edges[i][1] == u) {
                    v = edges[i][0];
                    if (visited[v] == 0) {
                        p[v] = u ;
                        q.push(v);
                        visited[v] = 1;
                    }
                    else {
                        if (p[u] != v) return true;
                    }
                }
            }
            if (q.empty()) {
                for (int i = 0 ; i < V ; i++) {
                    if (visited[i] == 0) {q.push(i);p[i]=i;visited[i]=1;break;}
                }
            }
        }
        return false;
    }
};