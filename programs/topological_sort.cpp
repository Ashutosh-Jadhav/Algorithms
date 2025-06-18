class Solution {
  public:
    void dfs(int i , vector<int>& v ,vector<int>& ans, vector<vector<int>>& adj) {
        if (v[i]) return ;
        v[i] = 1;
        for (int j = 0 ; j < adj[i].size() ; j++) {
            dfs(adj[i][j],v,ans,adj);
        }
        ans.push_back(i);
        return;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V,vector<int>());
        for (int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> v(V,0);
        vector<int> ans;
        for (int i = 0 ; i < V ; i++){
            if (!v[i]) dfs(i,v,ans,adj);
        }
        reverse(ans.begin(),ans.end());
        // for (auto m : ans) cout << m << " ";
        return ans;
    }
};