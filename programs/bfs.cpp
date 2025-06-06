// gfg problem

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int u,n = adj.size() ;
        vector<int> v(n,0) ;
        vector<int> bfs ;
        queue<int> q;
        q.push(0);
        bfs.push_back(0) ;
        v[0] = 1 ;
        while (!q.empty()){
            u = q.front();
            q.pop();
            for (int i = 0 ; i < adj[u].size() ;i++){
                if (v[adj[u][i]] == 0) {
                    v[adj[u][i]] = 1 ;                             // visited not yet explored
                    q.push(adj[u][i]);
                    bfs.push_back(adj[u][i]);
                }
            }
        }
        return bfs ;
    }
};