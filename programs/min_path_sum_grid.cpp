// memoization

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m, n ;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        ans[0][0] = grid[0][0];
        for (int i = 1 ; i < m ; i++)
        {
            ans[i][0] = grid[i][0] + ans[i-1][0];
        }
        for(int j = 1 ; j < n ; j++)
        {
            ans[0][j] = grid[0][j] + ans[0][j-1];
        }
        return f(m-1, n-1, ans,grid);
    }
    int f(int i, int j , vector<vector<int>>& ans,vector<vector<int>>& grid)
    {
        if (i < 0 || j < 0 )
        {
            return 0;
        }
        if (ans[i][j] != -1)
        {
            return ans[i][j];
        }
        if (f(i-1,j,ans,grid) < f(i,j-1,ans,grid)){
            return ans[i][j] = grid[i][j] + f(i-1,j,ans,grid);
        }
        return ans[i][j] = grid[i][j] + f(i,j-1,ans,grid);
    }
};



// Tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m,n;
        m = grid.size();
        n = grid[0].size();
        int ans[m][n];
        ans[0][0] = grid[0][0];
        for (int i = 1 ; i < grid.size();i++)
        {
            ans[i][0] = ans[i-1][0] + grid[i][0];
        }
        for (int j = 1 ; j < grid[0].size() ; j++)
        {
            ans[0][j] = ans[0][j-1] + grid[0][j];
        }
        for (int i = 1 ; i < grid.size() ; i++)
        {
            for (int j = 1 ; j < grid[0].size() ; j++)
            {
                if (ans[i-1][j] < ans[i][j-1])
                {
                    ans[i][j] = grid[i][j] + ans[i-1][j];
                }
                else
                {
                    ans[i][j] = grid[i][j] + ans[i][j-1];
                }
            }
        }
        return ans[grid.size()-1][grid[0].size()-1];
    }
};