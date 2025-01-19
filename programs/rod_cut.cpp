// BottomUp

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> ans(n,vector<int>(n+1,0));
        for (int j = 1 ; j<n+1;j++) ans[0][j] = ans[0][j-1] + price[0];
        for (int i = 1 ; i < n ; i++){
            for (int j = 0 ; j < n+1 ; j++){
                if (j>=i+1) ans[i][j] = max(ans[i-1][j] , ans[i][j-i-1]+price[i]);
                else ans[i][j] = ans[i-1][j] ;
            }
        }
        return ans[n-1][n];
    }
};

// space optimized

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> ans(n+1,0);
        for (int j = 1 ; j < n+1 ; j++) ans[j] = ans[j-1]+price[0];
        for (int i = 0 ; i < n ; i++){
            for (int j = i+1 ; j < n+1 ; j++){
                ans[j] = max(ans[j],ans[j-i-1]+price[i]);
            }
        }
        return ans[n];
    }
};
