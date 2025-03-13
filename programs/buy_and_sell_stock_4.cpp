// Bottom Up

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> ans(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));
            for (int i = n-1 ; i >= 0 ; i--){
                for (int j = 0 ; j < 2 ; j++){
                    for (int k1 = 1 ; k1 <= k ; k1++){
                        if (j == 0 ){
                            ans[i][j][k1] = max(-prices[i] + ans[i+1][1][k1] , ans[i+1][j][k1]);
                        }
                        else {
                            ans[i][j][k1] = max(prices[i] + ans[i+1][0][k1-1] , ans[i+1][j][k1]);
                        }
                    }
                }
            }
            return ans[0][0][k];
        }
    };


    // Space Optimized

    class Solution {
        public:
            int maxProfit(int k, vector<int>& prices) {
                int n = prices.size();
                vector<vector<vector<int>>> ans(2,vector<vector<int>> (2,vector<int> (k+1,0)));
                for (int i = n-1 ; i >= 0 ; i--){
                    for (int j = 0 ; j < 2 ; j++){
                        for (int k1 = 1 ; k1 <= k ; k1++){
                            if (j == 0 ){
                                ans[i%2][j][k1] = max(-prices[i] + ans[(i+1)%2][1][k1] , ans[(i+1)%2][j][k1]);
                            }
                            else {
                                ans[i%2][j][k1] = max(prices[i] + ans[(i+1)%2][0][k1-1] , ans[(i+1)%2][j][k1]);
                            }
                        }
                    }
                }
                return ans[0][0][k];
            }
        };