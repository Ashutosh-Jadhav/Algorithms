// gfg problem


class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int u, n = adj.size() ;
        
        vector<int> v(n,0);
        stack<int> st;
        vector<int> dfs ;
        
        int start = 0 ;
        v[start] = 1 ;
        st.push(start);
        dfs.push_back(start);
        
        while(!st.empty()){
            u = st.top();
            // st.pop();
            for(int i = 0 ; i< adj[u].size() ; i++) {
                if (i == adj[u].size()-1) {st.pop();}
                if (v[adj[u][i]] == 0) {
                    v[adj[u][i]] = 1;
                    st.push(adj[u][i]);
                    dfs.push_back(adj[u][i]);
                    break;
                }
            }
        }
        return dfs ;
    }
};