// Bottom Up           Space optimization has something to learn

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>> ans(m,vector<int>(n,0));
            if (obstacleGrid[0][0] == 1) ans[0][0] = 0;
            else ans[0][0] = 1;
            for (int i = 1 ; i < m ; i++){
                if(obstacleGrid[i][0] == 1 || ans[i-1][0] == 0) ans[i][0] = 0;
                else ans[i][0] = 1;
            }
            for (int j = 1 ; j < n ; j++){
                if(obstacleGrid[0][j] == 1 || ans[0][j-1]==0) ans[0][j] = 0;
                else ans[0][j] = 1;
            }
            for (int i = 1 ; i < m ; i++){
                for (int j = 1 ; j < n ; j++){
                    if (obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] ==1) continue;
                    else if (obstacleGrid[i][j] == 1) continue;
                    else if (obstacleGrid[i][j-1] == 1) ans[i][j] = ans[i-1][j];
                    else if(obstacleGrid[i-1][j] == 1) ans[i][j] = ans[i][j-1];
                    else ans[i][j] = ans[i-1][j] + ans[i][j-1];
                }
            }
            return ans[m-1][n-1];
        }
    };


// Space optimized    This one is somewhat unique

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>> ans(2,vector<int>(n,0));
            if (obstacleGrid[0][0] == 1) ans[0][0] = 0;
            else ans[0][0] = 1;
            for (int i = 1 ; i < min(m,2) ; i++){
                if(obstacleGrid[i][0] == 1 || ans[(i-1)%2][0] == 0) ans[i%2][0] = 0;
                else ans[i%2][0] = 1;
            }
            for (int j = 1 ; j < n ; j++){
                if(obstacleGrid[0][j] == 1 || ans[0][j-1]==0) ans[0][j] = 0;
                else ans[0][j] = 1;
            }
            for (int i = 1 ; i < m ; i++){
                if (obstacleGrid[i][0] == 1 || ans[(i-1)%2][0] == 0) ans[i%2][0] = 0;
                else ans[i%2][0] = 1;
                for (int j = 1 ; j < n ; j++){
                    if (ans[(i-1)%2][j] == 0 && ans[i%2][j-1] ==0) ans[i%2][j] = 0;
                    else if (obstacleGrid[i][j] == 1) ans[i%2][j] = 0;
                    else if (ans[i%2][j-1] == 0) ans[i%2][j] = ans[(i-1)%2][j];
                    else if(ans[(i-1)%2][j] == 0) ans[i%2][j] = ans[i%2][j-1];
                    else ans[i%2][j] = ans[(i-1)%2][j] + ans[i%2][j-1];
                }
            }
            return ans[(m-1)%2][n-1];
        }
    };


