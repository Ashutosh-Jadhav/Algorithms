// Bottom Up dp
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<int>ans (n,0);
            int buyed=0,max=0,sell = 0;
            for (int i = 1 ; i < n ; i++){
                if (prices[i] > prices[sell]) {
                    ans[i] = ans[i-1]+prices[i] - prices[sell];
                    sell = i;
                }
                else if (prices[i] < prices[buyed]){
                    buyed = i ;
                    sell = i;
                    ans[i] = 0;
                }
                else {
                    ans[i] = ans[i-1];
                }
                if (ans[i] > max) max = ans[i];
            }
            return max;
        }
    };

// Space optimized

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int buyed=0,max=0,sell = 0,curr=0,prev = 0;
            for (int i = 1 ; i < prices.size() ; i++){
                if (prices[i] > prices[sell]) {
                    curr = prev+prices[i] - prices[sell];
                    sell = i;
                }
                else if (prices[i] < prices[buyed]){
                    buyed = i ;
                    sell = i;
                    curr = 0;
                }
                else {
                    curr = prev;
                }
                if (curr > max) max = curr;
                prev = curr;
            }
            return max;
        }
    };