// Working solution (new approach)         best case :- O(E) worst case :- O(V*E)

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        int u,v1,w;
        vector<int> in_q(V,0);
        queue<int> q ;
        vector<int> v(V,0);
        vector<int> c(V,1e5 + 1);
        vector<vector<pair<int,int>>>adj (V,vector<pair<int,int>>());
        for (int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }
        q.push(0);            // given 0 is the source
        c[0] = 0 ; v[0] = 1; in_q[0] = 1;
        while(!q.empty()) {
            u = q.front() ; q.pop() ; in_q[u] = 0;
            for (int i = 0 ; i < adj[u].size() ; i++) {
                v1 = adj[u][i].first; w = adj[u][i].second;
                if (c[v1] > c[u]+w) c[v1] = c[u] + w;
                if(!in_q[v1]) {q.push(v1);in_q[v1]=1;}
            }
        }
        for (int i = 0 ; i < V ; i++) {
            if (c[i] > 1e5) c[i] = -1;
        }
        return c;
    }
};

// O(V+E)

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        int u,v1,w;
        queue<int> q ;
        vector<int> in_degree(V,0);
        vector<int> c(V,1e5 + 1);
        vector<int> ans;
        vector<vector<pair<int,int>>>adj (V,vector<pair<int,int>>());
        for (int i = 0 ; i < edges.size() ; i++) {
            in_degree[edges[i][1]]++;
            adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }
        for (int i =0 ; i < V ; i++) {
            if (!in_degree[i]) q.push(i);
        }
        c[0] = 0 ;
        while(!q.empty()) {
            u = q.front() ; q.pop() ;ans.push_back(u);
            for (int i = 0 ; i < adj[u].size() ; i++) {
                v1 = adj[u][i].first;
                in_degree[v1]--;
                if(!in_degree[v1]) {q.push(v1);}
            }
        }
        for (int i = 0 ;  i < ans.size() ; i++) {
            u = ans[i];
            for (int j = 0 ; j < adj[u].size() ; j++) {
                v1 = adj[u][j].first; w = adj[u][j].second;
                if (c[v1] > c[u]+w) c[v1] = c[u]+w;
            }
        }
        for (int i = 0 ; i < V ; i++) {
            if (c[i] > 1e5) c[i] = -1;
        }
        return c;
    }
};



// TLE solution

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        int u,v1,w;
        queue<int> q ;
        vector<int> v(V,0);
        vector<int> c(V,1e5 + 1);
        vector<vector<pair<int,int>>>adj (V,vector<pair<int,int>>());
        for (int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }
        q.push(0);            // given 0 is the source
        c[0] = 0 ; v[0] = 1;
        while(!q.empty()) {
            u = q.front() ; q.pop() ;
            for (int i = 0 ; i < adj[u].size() ; i++) {
                v1 = adj[u][i].first; w = adj[u][i].second;
                if (c[v1] > c[u]+w) c[v1] = c[u] + w;
                q.push(v1);
            }
        }
        for (int i = 0 ; i < V ; i++) {
            if (c[i] > 1e5) c[i] = -1;
        }
        return c;
    }
};
