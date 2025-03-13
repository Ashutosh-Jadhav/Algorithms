// Dp 
// Bottom Up ,space optimized

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            vector<vector<int>> ans(2,vector<int> (2,0));
            for (int i = prices.size()-1 ; i >= 0 ; i--){
                for (int j = 0 ; j < 2 ; j++){
                    if (j == 0){
                        ans[i%2][j] = max(ans[(i+1)%2][1] - prices[i] , ans[(i+1)%2][j]);
                    }
                    else {
                        ans[i%2][j] = max(prices[i] + ans[(i+1)%2][0] , ans[(i+1)%2][j]);
                    }
                }
            }
            return ans[0][0];
        }
    };


// greedy
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int sum = 0 ,  buy = 0,curr ;
            for (int i = 1 ; i < prices.size() ; i++){
                if (prices[buy] < prices[i]){
                    curr = prices[i] - prices[buy];
                    buy = i;
                    sum += curr;
                }
                else if (prices[i] < prices[buy]){
                    buy = i ;
                    curr = 0;
                }
            }
            return sum;
        }
    };