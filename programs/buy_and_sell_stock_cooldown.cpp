// Bottom Up

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<int>> ans(n+2,vector<int> (2,0));
            for (int i = n-1; i >= 0 ; i--){
                for (int j = 0 ; j < 2 ; j++){
                    if (j==0){
                        ans[i][j] = max(ans[i+1][1]-prices[i],ans[i+1][j]);
                    }
                    else {
                        ans[i][j] = max(prices[i] + ans[i+2][0] , ans[i+1][j]);
                    }
                }
            }
            return ans[0][0];
        }
    };

// Space Optimized

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            vector<vector<int>> ans(3,vector<int> (2,0));
            for (int i = prices.size()-1; i >= 0 ; i--){
                for (int j = 0 ; j < 2 ; j++){
                    if (j==0){
                        ans[i%3][j] = max(ans[(i+1)%3][1]-prices[i],ans[(i+1)%3][j]);
                    }
                    else {
                        ans[i%3][j] = max(prices[i] + ans[(i+2)%3][0] , ans[(i+1)%3][j]);
                    }
                }
            }
            return ans[0][0];
        }
    };