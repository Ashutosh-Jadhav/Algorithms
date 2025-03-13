// Bottom Up
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int k = 2 ;
            vector<vector<vector<int>>> ans(n+1,vector<vector<int>> (2,vector<int> (3,0)));
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
            // for (int i = 0 ; i < n ; i++){
            //     for (int j = 0 ; j < 2 ; j++){
            //         for (int k = 0 ; k < 3; k++){
            //             cout << ans[i][j][k] << " ";
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }
            return ans[0][0][2];
        }
    };

// sapce optimized

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> ans(2,vector<vector<int>> (2,vector<int> (3,0)));
            for (int i = n-1 ; i >= 0 ; i--){
                for (int j = 0 ; j < 2 ; j++){
                    for (int k1 = 1 ; k1 <= 2 ; k1++){
                        if (j == 0 ){
                            ans[i%2][j][k1] = max(-prices[i] + ans[(i+1)%2][1][k1] , ans[(i+1)%2][j][k1]);
                        }
                        else {
                            ans[i%2][j][k1] = max(prices[i] + ans[(i+1)%2][0][k1-1] , ans[(i+1)%2][j][k1]);
                        }
                    }
                }
            }
            return ans[0][0][2];
        }
    };