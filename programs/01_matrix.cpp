// TLE   , try optimizing using dp

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m,n; m = mat.size() ; n = mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        // queue<pair<int,int>> q;
        vector<vector<int>> ans(m,vector<int>(n,0));
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (mat[i][j]) {
                    ans[i][j] = bfs(i,j,visited,ans,mat);
                }
            }
        }
        return ans ;
    }

private:
    int bfs(int i, int j , vector<vector<int>>visited , vector<vector<int>>& ans , vector<vector<int>>& mat) {
        int x,y ;
        queue<pair<int,int>> q;
        vector<vector<int>> c(mat.size() , vector<int> (mat[0].size() , 0));
        q.push(make_pair(i,j));
        visited[i][j] = 1;
        while(!q.empty()) {
            x = q.front().first; y = q.front().second;
            q.pop();
            if (x > 0 && !visited[x-1][y]) {
                q.push(make_pair(x-1,y));
                visited[x-1][y] = 1 ;
                c[x-1][y] = c[x][y] + 1 ;
                if (mat[x-1][y] == 0) return c[x-1][y] ;
            }
            if (x < mat.size() - 1 && !visited[x+1][y]) {
                q.push(make_pair(x+1,y));
                visited[x+1][y] = 1 ;
                c[x+1][y] = c[x][y] + 1 ;
                if (mat[x+1][y] == 0) return c[x+1][y];
            }
            if (y > 0 && !visited[x][y-1]) {
                q.push(make_pair(x,y-1));
                visited[x][y-1] = 1 ;
                c[x][y-1] = 1+ c[x][y] ;
                if (mat[x][y-1] == 0) return c[x][y-1];
            }
            if (y < mat[0].size() - 1 && !visited[x][y+1]) {
                q.push(make_pair(x,y+1));
                visited[x][y+1] = 1 ;
                c[x][y+1] = 1+ c[x][y] ;
                if (mat[x][y+1] == 0) return c[x][y+1] ;
            }
            
        }
        return 0 ;
    }
};


// Accepted solution

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m,n,x,y;
        m = mat.size(); n = mat[0].size();
        vector<vector<int>> ans(m,vector<int> (n,0));
        vector<vector<int>> v(m,vector<int> (n,0));
        // vector<vector<int>> level(m,vector<int> (n,0))
        queue<pair<int,int>> q;
        for (int i = 0 ; i < m ; i++) {
            for ( int j = 0 ; j < n ; j++) {
                if(!mat[i][j]) {q.push(make_pair(i,j));v[i][j] = 1;}
            }
        }
        while(!q.empty()) {
            x = q.front().first; y = q.front().second;
            q.pop();
            if (x > 0 && !v[x-1][y] && mat[x-1][y]) {
                v[x-1][y] = 1 ;
                ans[x-1][y] = ans[x][y] +1 ;
                q.push(make_pair(x-1,y));
            }
            if (x < m-1 && !v[x+1][y] && mat[x+1][y]) {
                v[x+1][y] = 1 ;
                ans[x+1][y] = ans[x][y] +1;
                q.push(make_pair(x+1,y));
            }
            if (y > 0 && !v[x][y-1] && mat[x][y-1]) {
                v[x][y-1] = 2;
                ans[x][y-1] = 1+ ans[x][y] ;
                q.push(make_pair(x,y-1));
            }
            if (y < n-1 && !v[x][y+1] && mat[x][y+1]) {
                v[x][y+1] = 1;
                ans[x][y+1] = 1+ans[x][y];
                q.push(make_pair(x,y+1));
            }
        }
        return ans;
    }
};