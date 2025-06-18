class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int u;
        vector<int> in_degree(V,0);
        // vector<int> dl(V,0);
        queue<int> q;
        vector<int> ans;
        vector<vector<int>> adj(V,vector<int> ());
        for (int i = 0 ; i < edges.size() ; i++) {
            in_degree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for (int i = 0 ;i < V ; i++) {
            if (!in_degree[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            u = q.front(); q.pop();
            ans.push_back(u);
            for (auto m : adj[u]) {
                in_degree[m]--;
                if (!in_degree[m]) q.push(m);
            }
        }
        if (ans.size() != V) return {};
        // for (auto m : ans) cout << m << " ";
        return ans;
    }
};