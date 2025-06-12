class Solution {
  private:
    bool dfs(int u , vector<int>& visited, vector<int>& p , vector<vector<int>>& edges) {
        int v;
        visited[u] = 1;
        for (int i = 0 ; i < edges.size() ; i++) {
            if (edges[i][0] == u) {
                v = edges[i][1] ;
                if (visited[v] == 0) {p[v] = u ;if(dfs(v,visited,p,edges)) return true;}
                else if (visited[v] == 1 && p[u] != v) return true;
            }
            if (edges[i][1] == u ) {
                v = edges[i][0] ;
                if (visited[v] == 0) {p[v] = u ;if(dfs(v,visited,p,edges)) return true ;}
                else if (visited[v] == 1 && p[u] != v) return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> visited(V,0);
        vector<int> p(V,-1);
        for (int i = 0 ; i < V ; i++){
            if(!visited[i]) {if(dfs(i,visited,p,edges)) return true;}
        }
        return false;
    }
};