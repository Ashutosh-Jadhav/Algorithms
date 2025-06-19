// using priority_queue


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        const int INF = 1e9;
        vector<int> d(V,INF);
        vector<int> v(V,0);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>());
        int u,v1,w;
        for (int i =0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }
        d[src] = 0;
        pq.push({d[src],src});
        while(!pq.empty()) {
            u = pq.top()[1] ; pq.pop() ;
            if (v[u]) continue;
            v[u] = 1 ;
            for (int i = 0 ; i < adj[u].size(); i++) {
                v1 = adj[u][i].first; w = adj[u][i].second;
                if (!v[v1] && d[v1] > d[u]+w) {d[v1] = d[u]+w;pq.push({d[v1],v1});}
            }
        }
        return d;
    }
};

// using set 

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        const int INF = 1e9;
        vector<int> d(V,INF);
        vector<int> v(V,0);
        vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>());
        set<pair<int,int>> s;
        int u,v1,w;
        for (int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }
        d[src] = 0;
        s.insert(make_pair(d[src],src));
        while (!s.empty()) {
            u = s.begin()->second; s.erase(s.begin());
            if (v[u]) continue;
            v[u] = 1;
            for (int i = 0 ; i < adj[u].size() ; i++) {
                v1 = adj[u][i].first; w = adj[u][i].second;
                if (v[v1]) continue;
                if (d[v1] > d[u]+w) {
                    if (d[v1] != INF) {
                        s.erase({d[v1],v1});
                    }
                    d[v1] = d[u] + w;
                    s.insert(make_pair(d[v1],v1));
                }
            }
        }
        return d;
    }
};