class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        int c,idx,min = INF;
        vector<vector<int>> dist(n,vector<int>(n,INF));
        for (int i = 0 ; i < n ; i++) dist[i][i] = 0;
        for (int i = 0 ; i < edges.size() ; i++) {
            if (edges[i][2] <= distanceThreshold){
                dist[edges[i][0]][edges[i][1]] = edges[i][2];
                dist[edges[i][1]][edges[i][0]] = edges[i][2];
            }
        }
        for (int k = 0 ; k < n ; k++) {
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    if (dist[i][k]+dist[k][j] > distanceThreshold) continue;
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j] ;
                    }
                }
            }
        }
        // for (int i = 0 ; i < n ; i++) {
        //     for (int j = 0 ; j < n ; j++) {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0 ; i < n ; i++) {
            c = 0;
            for (int j = 0 ; j < n ; j++) {
                if (dist[i][j] < INF) c++;
            }
            if (min >= c) {min = c ; idx = i;}
        }
        return idx;
    }
};