// Working solution

class Solution {
  public:
    void dfs(int x , int y , int i , int j , vector<pair<int,int>>& shape,vector<vector<int>>& v,vector<vector<int>>& grid) {
        int m,n ; m = grid.size() ; n = grid[0].size() ;
        if (x<0 || y<0 || x>=m || y>=n || v[x][y] || !grid[x][y]) return;
        v[x][y] = 1 ;
        shape.push_back(make_pair(x-i,y-j));
        dfs(x+1,y,i,j,shape,v,grid);
        dfs(x-1,y,i,j,shape,v,grid);
        dfs(x,y+1,i,j,shape,v,grid);
        dfs(x,y-1,i,j,shape,v,grid);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m,n ; m = grid.size() ; n = grid[0].size() ;
        set<vector<pair<int,int>>> ans;
        vector<vector<int>> v(m,vector<int> (n,0));
        for (int i= 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (!v[i][j] && grid[i][j]) {
                    vector<pair<int,int>> shape;
                    dfs(i,j,i,j,shape,v,grid);
                    ans.insert(shape);
                }
            }
        }
        return ans.size();
    }
};


// TLE Solution

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m,n,x,y,no_edges=0,no_vertices=0 ; m = grid.size() ; n = grid[0].size() ;
        pair<int,int> top_left;
        vector<vector<int>> v(m,vector<int> (n,0));
        queue<pair<int,int>> q;
        vector<pair<pair<int,int>,pair<int,int>>> ans;
        for (int i = 0 ; i < m ; i++ ) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 1 && !v[i][j]) {
                    v[i][j] = 1 ;
                    q.push(make_pair(i,j));
                    top_left = q.front(); no_vertices=1;no_edges=0;
                    while (!q.empty()) {
                        x = q.front().first; y = q.front().second ; q.pop();
                        if (x > 0 && grid[x-1][y]) {
                            no_edges++;
                            if (!v[x-1][y]) {
                                no_vertices++; q.push(make_pair(x-1,y));
                                v[x-1][y] = 1;
                            }
                        }
                        if (x < m-1 && grid[x+1][y]) {
                            no_edges++;
                            if (!v[x+1][y]) {
                                no_vertices++; q.push(make_pair(x+1,y));
                                v[x+1][y] = 1 ;
                            }
                        }
                        if ( y > 0 && grid[x][y-1]){
                            no_edges++;
                            if (!v[x][y-1]) {
                                no_vertices++; q.push(make_pair(x,y-1));
                                v[x][y-1] = 1 ;
                            }
                        }
                        if (y < n-1 && grid[x][y+1]){
                            no_edges++;
                            if (!v[x][y+1]) {
                                no_vertices++; q.push(make_pair(x,y+1));
                                v[x][y+1] = 1;
                            }
                        }
                    }
                    ans.push_back(make_pair(make_pair(no_vertices,no_edges),top_left));
                }
            }
        }
        vector<int> dl(ans.size(),0); int x2,y2,c=0,flag=0;
        queue<pair<int,int>> q2;
        // vector<vector<int>> v2(m,vector<int> (n,0));
        for (int i = 0 ; i < ans.size() ; i++) {
            if (dl[i]) continue;
            for (int j = i+1 ; j < ans.size() ; j++) {
                if (dl[j]) continue;
                if (ans[i].first.first == ans[j].first.first && ans[i].first.second == ans[j].first.second) {
                    q = queue<pair<int,int>>(); q2 = queue<pair<int,int>>();
                    vector<vector<int>> v2(m,vector<int> (n,0)); flag=0;
                    q.push(ans[i].second); q2.push(ans[j].second); v2[ans[i].second.first][ans[i].second.second] =  1;
                    while(!q.empty()) {
                        x = q.front().first ; y = q.front().second; q.pop();
                        x2 = q2.front().first ; y2 = q2.front().second; q2.pop();
                        if (x > 0 && grid[x-1][y]) {
                            if (x2 == 0 || grid[x-1][y] != grid[x2-1][y2] ) {flag=1;break;}
                            if (!v2[x-1][y]) {v2[x-1][y] = 1 ; q.push(make_pair(x-1,y)); q2.push(make_pair(x2-1,y2));}
                        }
                        if ( x < m-1 && grid[x+1][y]) {
                            if ( x2 == m-1 || grid[x+1][y] != grid[x2+1][y2] ) {flag=1;break;}
                            if (!v2[x+1][y]) {v2[x+1][y] = 1 ; q.push(make_pair(x+1,y)); q2.push(make_pair(x2+1,y2));}
                        }
                        if (y > 0 && grid[x][y-1]) {
                            if (y2 == 0 || grid[x][y-1] != grid[x2][y2-1]) {flag=1;break;}
                            if (!v2[x][y-1]) {v2[x][y-1] = 1 ; q.push(make_pair(x,y-1)) ; q2.push(make_pair(x2,y2-1));}
                        }
                        if (y < n-1 && grid[x][y+1]) {
                            if (y2 == n-1 || grid[x][y+1] != grid[x2][y2+1]) {flag=1;break;}
                            if (!v2[x][y+1]) {v2[x][y+1] = 1 ; q.push(make_pair(x,y+1)) ; q2.push(make_pair(x2,y2+1));}
                        }
                        if (!flag && q.empty() && q2.empty()) {dl[j] = 1 ;c++;}
                    }
                }
            }
        }
        return ans.size() - c;
    }
};
