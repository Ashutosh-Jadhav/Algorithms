class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n,m,x,y,c=0 ;
        n = grid[0].size(); m = grid.size() ;
        queue<pair<int,int>> q;
        for (int j = 0 ; j < n ; j++) {
            if (grid[0][j] == 1) {q.push(make_pair(0,j)); grid[0][j] = 2 ;}
            if (grid[m-1][j] == 1) {q.push(make_pair(m-1,j)); grid[m-1][j] = 2;}
        }
        for (int i = 1 ; i < m-1 ;i++) {
            if (grid[i][0] == 1) {q.push(make_pair(i,0));grid[i][0] = 2;}
            if (grid[i][n-1] == 1) {q.push(make_pair(i,n-1)); grid[i][n-1] = 2 ;}
        }
        while(!q.empty()) {
            x = q.front().first; y = q.front().second; q.pop();
            if (x>0 && grid[x-1][y] == 1) {
                grid[x-1][y] = 2;
                q.push(make_pair(x-1,y));
            }
            if (x < m-1 && grid[x+1][y] == 1) {
                grid[x+1][y] = 2 ;
                q.push(make_pair(x+1,y));
            }
            if (y > 0 && grid[x][y-1] == 1) {
                grid[x][y-1]=2;
                q.push(make_pair(x,y-1));
            }
            if (y < n-1 && grid[x][y+1] == 1) {
                grid[x][y+1]=2;
                q.push(make_pair(x,y+1));
            }
        }
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 1) c++;
            }
        }
        return c;
    }
};