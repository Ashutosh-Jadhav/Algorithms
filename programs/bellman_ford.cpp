// initial approach

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int u,v,w;
        const int INF = 1e8;
        vector<vector<int>> d(V+1,vector<int>(V,INF));
        d[0][src] = 0;
        for (int l = 1 ; l <= V ; l++) {
            d[l] = d[l-1];
            for (int i = 0 ; i < edges.size() ; i++) {
                u = edges[i][0] ; v = edges[i][1] ; w = edges[i][2];
                if (d[l-1][u] !=INF && d[l][v] > d[l-1][u] + w) {
                    if (l == V) return {-1};
                    d[l][v] = d[l-1][u] + w;
                }
            }
        }
        return d[V-1];
    }
};


// space optimized and early stopping

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int u,v,w,c=0;
        const int INF = 1e8;
        vector<vector<int>> d(2,vector<int>(V,INF));
        d[0][src] = 0;
        for (int l = 1 ; l <= V ; l++) {
            d[l%2] = d[(l-1)%2];
            for (int i = 0 ; i < edges.size() ; i++) {
                u = edges[i][0] ; v = edges[i][1] ; w = edges[i][2];
                if (d[(l-1)%2][u] !=INF && d[l%2][v] > d[(l-1)%2][u] + w) {
                    if (l == V) return {-1};
                    c++;
                    d[l%2][v] = d[(l-1)%2][u] + w;
                }
            }
            if (!c) break;
            c = 0;
        }
        return d[(V-1)%2];
    }
};
