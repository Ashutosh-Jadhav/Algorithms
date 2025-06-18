class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());
        vector<int> in_degree(numCourses,0);
        queue<int> q;
        int u,c=0;
        for (int i = 0 ; i < prerequisites.size() ;i++) {
            in_degree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0 ; i < numCourses ; i++) {
            if (!in_degree[i]) q.push(i);
        }
        while(!q.empty()) {
            c++ ; u = q.front(); q.pop();
            for (int i = 0 ; i < adj[u].size();i++) {
                in_degree[adj[u][i]]--;
                if (!in_degree[adj[u][i]]) q.push(adj[u][i]);
            }
        }
        return numCourses == c;
    }
};