class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long m=1e9+7;
        const long long INF = 1e12;
        vector<vector<pair<long long,long long>>> adj(n,vector<pair<long long,long long>>());
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        vector<long long> d(n,INF);
        vector<long long> c(n,1);                      // number of ways
        long long u,v1,w,d1;
        for (int i = 0 ; i < roads.size() ; i++) {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        d[0] = 0 ; c[0] = 1;
        pq.push({d[0],0});
        while(!pq.empty()) {
            d1 = pq.top()[0]; u = pq.top()[1]; pq.pop();
            for (int i = 0 ; i < adj[u].size() ;i++) {
                v1 = adj[u][i].first; w = adj[u][i].second;
                if (d[v1] == d1 + w) c[v1] = (c[v1]+c[u])%m;
                if (d[v1] > d1+w) {
                    d[v1] = d1 + w; pq.push({d[v1],v1});c[v1] = c[u]%m;
                }
            }
        }
        return c[n-1] % m;
    }
};