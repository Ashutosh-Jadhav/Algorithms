class Solution {
public:
    void dfs(int u , vector<vector<int>>& adj ,vector<int>& v,vector<int>& p,vector<int>& disc,vector<int>& low , int t,vector<vector<int>>& bridges) {
        if (v[u]) return;
        v[u] = 1; disc[u] = t ; low[u] = t++;
        int v1;
        for (int i = 0; i < adj[u].size() ; i++) {
            v1 = adj[u][i] ;
            if (p[u] == v1) continue;
            else if (v[v1]) low[u] = min(low[u],disc[v1]);
            else {
                p[v1] = u ; 
                dfs(v1,adj,v,p,disc,low,t,bridges);
                low[u] = min(low[u],low[v1]);
                if (low[v1] > disc[u]) bridges.push_back({u,v1});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        const int INF = 1e8;
        vector<vector<int>> adj(n, vector<int>());
        vector<vector<int>> bridges;
        vector<int> v(n,0); vector<int> p(n,-1); vector<int> disc(n,-1); vector<int> low(n,-1);
        int t = 0 ;
        for (int i = 0 ; i < connections.size() ; i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for (int i = 0 ; i < n ; i++) {
            if (!v[i]) {
                dfs(i,adj,v,p,disc,low,t,bridges);
            }
        }
        return bridges;
    }
};