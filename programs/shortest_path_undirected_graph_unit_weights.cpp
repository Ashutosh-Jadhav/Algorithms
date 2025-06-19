class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> v(adj.size(),0);
        vector<int> c(adj.size(),-1);
        queue<int> q;
        int u ;
        q.push(src);
        c[src] = 0 ; v[src] = 1;
        while(!q.empty()) {
            u = q.front(); q.pop();
            for (int i = 0 ; i < adj[u].size() ; i++) {
                if (!v[adj[u][i]]) {q.push(adj[u][i]) ; c[adj[u][i]] = c[u] + 1;v[adj[u][i]] = 1;}
            }
        }
        return c ;
    }
};