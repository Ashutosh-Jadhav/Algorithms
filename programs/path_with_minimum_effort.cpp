class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n,m,x,y,n_x,n_y;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        const int INF = 1e9;
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> v(m,vector<int> (n,0));
        vector<vector<int>> d(m,vector<int> (n,INF));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        d[0][0] = 0;
        pq.push({d[0][0],0,0});
        while (!pq.empty()) {
            x = pq.top()[1]; y = pq.top()[2];pq.pop();
            if (v[x][y]) continue;
            v[x][y] = 1;
            for (int dir = 0 ; dir < 4 ; dir++) {
                n_x = x+dx[dir]; n_y = y+dy[dir];
                if (n_x >= 0 && n_x < m && n_y >= 0 && n_y < n && !v[n_x][n_y]) {
                    if (d[n_x][n_y] > max(d[x][y],abs(heights[n_x][n_y] - heights[x][y]))) {
                        d[n_x][n_y] = max(d[x][y] , abs(heights[x][y] - heights[n_x][n_y]));
                        pq.push({d[n_x][n_y],n_x,n_y});
                    }
                }
            }
        }
        return d[m-1][n-1];
    }
};