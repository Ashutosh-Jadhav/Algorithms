class Solution {
  public:
    bool dfs(int i , vector<int>& v , vector<vector<int>>& adj) {
        if (v[i] == 2) return false;
        if (v[i] == 1) return true;
        v[i] =  1;
        for (int j = 0 ; j < adj[i].size() ; j++) {
            if (dfs(adj[i][j],v,adj)) return true;
        }
        v[i] = 2 ;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V,vector<int> ()) ;
        vector<int>v (V,0);                      // 0 - not visited, 1 - in dfs stack , 2- explored
        for (int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(edges[i][1]) ;
        }
        for (int i = 0 ; i < V ; i++) {
            if (!v[i]) {
                if (dfs(i,v,adj)) return true;
            }
        }
        return false;
    }
};