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