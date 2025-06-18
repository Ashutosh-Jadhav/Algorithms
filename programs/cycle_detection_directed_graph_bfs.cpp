class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V,vector<int>());
        vector<int> in_degree(V,0);
        queue<int> q;
        int u,c = 0 ;
        for (int i = 0 ; i < edges.size(); i++) {
            in_degree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for (int i = 0 ; i < V ; i++) {
            if (!in_degree[i]) q.push(i);
        }
        while(!q.empty()) {
            u = q.front() ; q.pop(); c++;
            for (int i = 0 ; i < adj[u].size() ; i++) {
                in_degree[adj[u][i]]--;
                if (!in_degree[adj[u][i]]) q.push(adj[u][i]);
            }
        }
        return c != V;
    }
};