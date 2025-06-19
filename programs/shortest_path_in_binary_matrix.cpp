class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n,x,y,new_x,new_y; n = grid.size();
        int dx[] = {1,-1,0,0,1,-1,1,-1};
        int dy[] = {0,0,1,-1,1,1,-1,-1};
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<int>> v(n,vector<int>(n,0));
        vector<vector<int>> c(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        v[0][0] = 1 ; c[0][0] = 1;
        while(!q.empty()) {
            x = q.front().first; y = q.front().second; q.pop();
            for (int dir = 0 ; dir < 8 ; dir++) {
                new_x = x + dx[dir];
                new_y = y + dy[dir];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && !v[new_x][new_y] && !grid[new_x][new_y]){
                    c[new_x][new_y] = 1+c[x][y];
                    v[new_x][new_y] = 1;
                    q.push(make_pair(new_x,new_y));
                }
            }
        }
        return c[n-1][n-1];
    }
};

// can work with just count 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n,x,y,new_x,new_y; n = grid.size();
        int dx[] = {1,-1,0,0,1,-1,1,-1};
        int dy[] = {0,0,1,-1,1,1,-1,-1};
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        if (n == 1) return 1;
        // vector<vector<int>> v(n,vector<int>(n,0));
        vector<vector<int>> c(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        // v[0][0] = 1 ;
        c[0][0] = 1;
        while(!q.empty()) {
            x = q.front().first; y = q.front().second; q.pop();
            for (int dir = 0 ; dir < 8 ; dir++) {
                new_x = x + dx[dir];
                new_y = y + dy[dir];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && c[new_x][new_y] == -1 && !grid[new_x][new_y]){
                    c[new_x][new_y] = 1+c[x][y];
                    // v[new_x][new_y] = 1;
                    q.push(make_pair(new_x,new_y));
                }
            }
        }
        return c[n-1][n-1];
    }
};