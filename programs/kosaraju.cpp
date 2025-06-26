//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int u , vector<vector<int>>& adj , vector<int>& v, vector<pair<int,int>>& f,int& t) {
        if (v[u]) return;
        int v1;
        v[u] = 1;t++;
        for (int i = 0 ; i < adj[u].size() ; i++) {
            v1 = adj[u][i];
            dfs(v1,adj,v,f,t);
        }
        f.push_back(make_pair(u,t++));
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size(); 
        vector<int> v(n,0); vector<pair<int,int>> f; vector<int> v2(n,0);
        vector<pair<int,int>> f2;
        vector<vector<int>> adj2(n,vector<int>());
        int t = 0 ,ans=0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < adj[i].size() ; j++) {
                adj2[adj[i][j]].push_back(i);
            }
        }
        for (int i = 0 ; i < n ; i++) {
            if (!v[i]) dfs(i,adj,v,f,t);
        }
        sort(f.begin(),f.end(),[](const pair<int,int>& a , const pair<int,int>& b) {return a.second > b.second;});
        for (int i = 0 ; i < f.size() ;i++) {
            if (!v2[f[i].first]) {
                dfs(f[i].first,adj2,v2,f2,t); ans++;
            }
        }
        return ans;
    }
};


// get strongly connected components

//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int u , vector<vector<int>>& adj , vector<int>& v, vector<pair<int,int>>& f,int& t) {
        if (v[u]) return;
        int v1;
        v[u] = 1;t++;
        for (int i = 0 ; i < adj[u].size() ; i++) {
            v1 = adj[u][i];
            dfs(v1,adj,v,f,t);
        }
        f.push_back(make_pair(u,t++));
    }
    void dfs2(int u , vector<vector<int>>& adj , vector<int>& v,vector<int>& scc) {
        if (v[u]) return;
        int v1;
        scc.push_back(u);
        v[u] = 1;
        for (int i = 0 ; i < adj[u].size() ; i++) {
            v1 = adj[u][i];
            dfs2(v1,adj,v,scc);
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size(); 
        vector<int> v(n,0); vector<pair<int,int>> f; vector<int> v2(n,0);
        vector<vector<int>> adj2(n,vector<int>());
        vector<vector<int>> ans ;
        vector<int> scc;
        int t = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < adj[i].size() ; j++) {
                adj2[adj[i][j]].push_back(i);
            }
        }
        for (int i = 0 ; i < n ; i++) {
            if (!v[i]) dfs(i,adj,v,f,t);
        }
        sort(f.begin(),f.end(),[](const pair<int,int>& a , const pair<int,int>& b) {return a.second > b.second;});
        for (int i = 0 ; i < f.size() ;i++) {
            if (!v2[f[i].first]) {
                scc.clear();
                dfs2(f[i].first,adj2,v2,scc); ans.push_back(scc);
            }
        }
        // for (auto i : ans) {
        //     for (auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        return ans.size();
    }
};