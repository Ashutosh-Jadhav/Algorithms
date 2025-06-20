class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF=1e9;
        int u,v1,w,max=0,c=0;
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> v(n,0);
        vector<int> d(n,INF);
        for (int i = 0 ; i < times.size() ; i++) {
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        d[k-1] = 0 ;
        pq.push({d[k-1],k-1});
        while(!pq.empty()) {
            u=pq.top()[1] ; pq.pop();
            if (v[u]) continue;
            v[u] = 1;c++;
            if(d[u] > max) max = d[u];
            for (int i = 0 ; i < adj[u].size() ; i++) {
                v1 = adj[u][i].first; w = adj[u][i].second;
                if (d[v1] > d[u]+w) {
                    d[v1] = d[u] + w ;
                    pq.push({d[v1],v1});
                }
            }
        }
        if (c != n) return -1;
        return max;
    }
};