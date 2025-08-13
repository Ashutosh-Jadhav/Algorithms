// first approach

class Solution {
public:
    void bfs(int i , int j , vector<vector<int>>& heights, vector<vector<int>>& ocean) {
        queue<pair<int,int>> q;
        int x,y,n_x,n_y,n,m; n = heights.size(); m = heights[0].size();
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        ocean[i][j] = 1;
        q.push({i,j});
        while(!q.empty()) {
            x = q.front().first; y = q.front().second; q.pop();
            for (int k = 0 ; k < 4 ; k++) {
                n_x = x+dx[k]; n_y = y+dy[k]; 
                if (n_x >= 0 && n_y >= 0 && n_x < n && n_y < m && !ocean[n_x][n_y] && heights[n_x][n_y] >= heights[x][y]) {
                    ocean[n_x][n_y] = 1;
                    q.push({n_x,n_y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n,m ;
        n = heights.size(); m = heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<vector<int>> res;
        // queue<pair<int,int>> q;
        for (int i = 0 ; i < n ; i++) {
            if (!pacific[i][0]) bfs(i,0,heights,pacific);
        }
        for (int j = 0 ;j < m ; j++) {
            if (!pacific[0][j]) bfs(0,j,heights,pacific);
        }
        for (int i = 0 ; i < n ; i++) {
            if (!atlantic[i][m-1]) bfs(i,m-1,heights,atlantic);
        }
        for (int j = 0 ; j < m ; j++) {
            if (!atlantic[n-1][j]) bfs(n-1,j,heights,atlantic);
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (atlantic[i][j] && pacific[i][j]) res.push_back({i,j});
                cout << atlantic[i][j] << " ";
            }
            cout << endl;
        }
        return res;
    }
};

// faster with more space
class Solution {
public:
    void bfs(int i , int j , vector<vector<int>>& heights, vector<vector<int>>& ocean) {
        queue<pair<int,int>> q;
        int x,y,n_x,n_y,n,m; n = heights.size(); m = heights[0].size();
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        ocean[i][j] = 1;
        q.push({i,j});
        while(!q.empty()) {
            x = q.front().first; y = q.front().second; q.pop();
            for (int k = 0 ; k < 4 ; k++) {
                n_x = x+dx[k]; n_y = y+dy[k]; 
                if (n_x >= 0 && n_y >= 0 && n_x < n && n_y < m && !ocean[n_x][n_y] && heights[n_x][n_y] >= heights[x][y]) {
                    ocean[n_x][n_y] = 1;
                    q.push({n_x,n_y});
                }
            }
        }
    }
    void bfs_atlantic(int i , int j , vector<vector<int>>& heights, vector<vector<int>>& atlantic, vector<vector<int>>& pacific,vector<vector<int>>& res) {
        queue<pair<int,int>> q;
        int n,m,x,y,n_x,n_y; n = heights.size(); m = heights[0].size();
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        atlantic[i][j] = 1; q.push({i,j});
        if (pacific[i][j]) res.push_back({i,j});
        while(!q.empty()) {
            x = q.front().first; y = q.front().second; q.pop();
            for (int k = 0 ; k < 4 ; k++) {
                n_x = x+dx[k]; n_y = y+dy[k];
                if (n_x >=0 && n_y >= 0 && n_x < n && n_y < m && !atlantic[n_x][n_y] && heights[n_x][n_y] >= heights[x][y]) {
                    atlantic[n_x][n_y] = 1;
                    q.push({n_x,n_y});
                    if (pacific[n_x][n_y] == 1) res.push_back({n_x,n_y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n,m ;
        n = heights.size(); m = heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<vector<int>> res;
        // queue<pair<int,int>> q;
        for (int i = 0 ; i < n ; i++) {
            if (!pacific[i][0]) bfs(i,0,heights,pacific);
        }
        for (int j = 0 ;j < m ; j++) {
            if (!pacific[0][j]) bfs(0,j,heights,pacific);
        }
        for (int i = 0 ; i < n ; i++) {
            if (!atlantic[i][m-1]) bfs_atlantic(i,m-1,heights,atlantic,pacific,res);
        }
        for (int j = 0 ; j < m ; j++) {
            if (!atlantic[n-1][j]) bfs_atlantic(n-1,j,heights,atlantic,pacific,res);
        }
        // for (int i = 0 ; i < n ; i++) {
        //     for (int j = 0 ; j < m ; j++) {
        //         if (atlantic[i][j] && pacific[i][j]) res.push_back({i,j});
        //         cout << atlantic[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return res;
    }
};