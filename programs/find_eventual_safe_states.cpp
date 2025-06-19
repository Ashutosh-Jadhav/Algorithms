class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> out_degree(graph.size(),0);
        queue<int> q;
        vector<int> ans;
        vector<vector<int>> adj(graph.size() , vector<int> ());
        int u;
        for (int i = 0 ; i < graph.size() ; i++) {
            out_degree[i] += graph[i].size();
            for (auto m : graph[i]) {
                adj[m].push_back(i);
            }
        }
        for (int i = 0 ; i < graph.size(); i++) {
            if (!out_degree[i]) q.push(i);
        }
        while(!q.empty()) {
            u= q.front(); q.pop() ; ans.push_back(u);
            for (auto m : adj[u]) {
                out_degree[m]--;
                if (!out_degree[m]) q.push(m);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};