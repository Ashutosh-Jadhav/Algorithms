class Solution {
public:

    bool dfs(int i , vector<vector<int>>& graph , vector<int>& v,int set) {
        if (set == 1) v[i] = 2 ;
        else v[i] = 1;
        for (int j= 0 ; j < graph[i].size() ;j++) {
            if (!v[graph[i][j]]) {
                if (!dfs(graph[i][j],graph,v,v[i])) return false;
            }
            else if ( v[i] && v[i] == v[graph[i][j]]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> v(n,0);
        for (int i = 0 ;  i < n ; i++){
            if(!v[i] && !dfs(i,graph,v,2)) return false;
        }
        return true;
    }
};