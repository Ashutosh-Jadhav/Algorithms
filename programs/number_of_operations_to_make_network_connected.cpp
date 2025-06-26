// using disjoint union

class Solution {
public:
    int find(int u, vector<int>& par)  {
        if (par[u] != u) return par[u] = find(par[u],par);
        return u;
    }
    int disjoint(int u, int v, vector<int>& par) {
        return find(u,par) != find(v,par);
    }
    void union_by_rank(int u, int v , vector<int>& par,vector<int>& r){
        int uroot, vroot ;
        uroot = find(u,par); vroot = find(v,par);
        if (uroot == vroot) return;
        if (r[uroot] > r[vroot]) {
            par[vroot] = uroot;
        }
        else if(r[vroot] > r[uroot]) {
            par[uroot] = vroot;
        }
        else {
            par[uroot] = vroot;
            r[uroot]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        vector<int> par(n,0);
        vector<int> r(n,0);
        for (int i = 0 ; i < n ; i++) par[i]=i;             // n connected components when no edges
        int u,v,ans = n ;                            // return connected components -1
        for (int i = 0 ; i < connections.size() ; i++) {
            u = connections[i][0]; v = connections[i][1];
            if (disjoint(u,v,par)) {
                n--;
                union_by_rank(u,v,par,r);
            }
        }
        return n-1;
    }
};

// using dfs

class Solution {
public:
    void dfs(int i , vector<int>& v, vector<vector<int>>& adj) {
        if (v[i]) return;
        v[i] = 1;
        for (int j = 0 ; j < adj[i].size() ; j++) {
            dfs(adj[i][j],v,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        vector<int> v(n,0);
        vector<vector<int>> adj(n,vector<int> ());
        int ans = 0 ;
        for (int i = 0 ; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for (int i = 0 ; i < n ; i++) {
            if (!v[i]) {
                ans++;
                dfs(i,v,adj);
            }
        }
        return ans-1;
    }
};