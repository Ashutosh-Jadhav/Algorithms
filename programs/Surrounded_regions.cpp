class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m, n,x,y ;
        m = board.size() ; n = board[0].size();
        vector<vector<int>> v(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for (int j = 0 ; j < n ; j++) {
            if (board[0][j] == 'O') {
                v[0][j] = 1 ; q.push(make_pair(0,j));
            }
            if (board[m-1][j] == 'O') {
                v[m-1][j] = 1 ; q.push(make_pair(m-1,j));
            }
        }
        for (int i = 1 ; i < m-1 ; i++) {
            if (board[i][0] == 'O') {
                v[i][0] = 1 ; q.push(make_pair(i,0));
            }
            if (board[i][n-1] == 'O') {
                v[i][n-1] = 1 ; q.push(make_pair(i,n-1));
            }
        }
        while(!q.empty()) {
            x = q.front().first ; y = q.front().second; q.pop();
            if (x > 0 && !v[x-1][y] && board[x-1][y] == 'O'){
                v[x-1][y] = 1 ;
                q.push(make_pair(x-1,y));
            }
            if (x < m-1 && !v[x+1][y] && board[x+1][y] == 'O') {
                v[x+1][y]=1;
                q.push(make_pair(x+1,y));
            }
            if (y > 0 && !v[x][y-1] && board[x][y-1]=='O') {
                v[x][y-1] = 1 ;
                q.push(make_pair(x,y-1));
            }
            if ( y < n-1 && !v[x][y+1] && board[x][y+1] =='O') {
                v[x][y+1] = 1 ;
                q.push(make_pair(x,y+1));
            }
        }
        for (int i = 1 ; i < m-1 ; i++) {
            for (int j = 1 ; j < n-1 ; j++) {
                if (board[i][j] == 'O' && v[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
};