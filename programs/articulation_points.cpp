class Solution {
  public:
    void dfs(int u , vector<vector<int>>& adj,vector<int>& v,vector<int>& disc ,vector<int>& low,vector<int>& p, vector<int>& ans, int t){
        if (v[u]) return;
        int count=0;
        v[u] = 1 ; disc[u] = t++ ; low[u] = disc[u];
        for (auto v1 : adj[u]) {
            if (p[u] == v1) continue;
            if (v[v1]) low[u] = min(low[u],disc[v1]);
            else {
                p[v1] = u ; 
                dfs(v1,adj,v,disc,low,p,ans,t);
                count++;
                low[u] = min(low[u],low[v1]);
                if (low[v1] >= disc[u] && p[u] != -1) ans[u] = 1;
            }
        }
        if (p[u] == -1 && count > 1) ans[u]=1;
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V,vector<int>());
        vector<int> v(V,0); vector<int> disc(V,0); vector<int> low(V,0);
        vector<int> ans(V,0); vector<int>p (V,-1); vector<int> res;
        int t = 0 ;
        for (int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i =0 ; i < V ; i++) {
            if (!v[i]) dfs(i,adj,v,disc,low,p,ans,t);
        }
        for (int i = 0 ; i < V ; i++) {
            if (ans[i]) res.push_back(i);
        }
        if (res.empty()) return {-1};
        return res;
    }
};