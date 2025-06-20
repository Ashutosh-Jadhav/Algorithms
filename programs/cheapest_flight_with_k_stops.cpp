// using queue          , min

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int u,v1,w,w1,k1;
        const int INF = 1e9;
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>> ());
        vector<int> v(n,0);
        vector<pair<int,int>> d(n,{INF,0});                   // first is smallest distance, second is k stops
        // priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        queue<vector<int>> pq;
        for (int i = 0 ; i < flights.size() ; i++) {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        d[src] = {0,-1};
        pq.push({d[src].first,src,d[src].second});
        while(!pq.empty()) {
            // u = pq.top()[1]; w1 = pq.top()[0] ;k1 = pq.top()[2] ; pq.pop();
            u = pq.front()[1]; w1 = pq.front()[0] ; k1 = pq.front()[2]; pq.pop();
            v[u] = 1;
            for (int i = 0 ; i < adj[u].size() ; i++) {
                v1 = adj[u][i].first; w = adj[u][i].second;
                if ( d[v1].first > w1 + w && k1 < k) {
                    d[v1] = {w1+w,k1+1}; pq.push({d[v1].first,v1,d[v1].second});
                }
            }
        }
        if (d[dst].first == INF) return -1;
        return d[dst].first;
    }
};