// Bottom Up

class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<vector<int>> ans(n+1,vector<int> (2,0));
            for (int i = n-1; i >= 0 ; i--){
                for (int j = 0 ; j < 2 ; j++){
                    if (j == 0){
                        ans[i][j] = max(ans[(i+1)][1] - prices[i]-fee , ans[(i+1)][j]);
                    }
                    else {
                        ans[i][j] = max(ans[(i+1)][0] + prices[i]  , ans[(i+1)][j]);
                    }
                }
            }
            return ans[0][0];
        }
    };

// space optimized

class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<vector<int>> ans(2,vector<int> (2,0));
            for (int i = n-1; i >= 0 ; i--){
                for (int j = 0 ; j < 2 ; j++){
                    if (j == 0){
                        ans[i%2][j] = max(ans[(i+1)%2][1] - prices[i]-fee , ans[(i+1)%2][j]);
                    }
                    else {
                        ans[i%2][j] = max(ans[(i+1)%2][0] + prices[i]  , ans[(i+1)%2][j]);
                    }
                }
            }
            return ans[0][0];
        }
    };