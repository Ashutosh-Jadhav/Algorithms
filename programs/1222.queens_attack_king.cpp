class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& adj,vector<vector<int>>& ans, int dx, int dy){
        int n_x,n_y; n_x = x+dx; n_y = y+dy;
        if (n_x > 7 || n_y > 7 || n_x < 0 || n_y < 0) return;
        if (adj[n_x][n_y] == 1) {ans.push_back({n_x,n_y});return;}
        dfs(n_x,n_y,adj,ans,dx,dy);
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> adj(8,vector<int>(8,0));
        vector<vector<int>> ans;
        int dx[8] = {-1,0,1,1,1,0,-1,-1};
        int dy[8] = {-1,-1,-1,0,1,1,1,0};
        for (auto m : queens) {
            adj[m[0]][m[1]] = 1;
        }
        for (int i = 0 ; i < 8 ; i++)
            dfs(king[0],king[1],adj,ans,dx[i],dy[i]);
        return ans;
    }
};