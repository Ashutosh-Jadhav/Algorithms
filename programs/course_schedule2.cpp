class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> in_degree(numCourses,0);
        queue<int> q;
        vector<int> ans;
        int u;
        for (int i = 0  ; i < prerequisites.size() ; i++) {
            in_degree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0 ; i < numCourses ; i++) {
            if (!in_degree[i]) q.push(i);
        }
        while(!q.empty()) {
            u = q.front() ; q.pop(); ans.push_back(u);
            for (int i = 0 ; i < adj[u].size() ; i++) {
                in_degree[adj[u][i]]--;
                if (!in_degree[adj[u][i]]) q.push(adj[u][i]);
            }
        }
        if (ans.size() != numCourses) return {};
        else return ans;
    }
};