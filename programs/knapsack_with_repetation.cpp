class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> ans(n,vector<int> (capacity+1,0));
        // for (int i = 0 ; i < n ; i++) ans[i][0] = 0;
        if (wt[0] <= capacity) ans[0][wt[0]] = val[0];
        for (int j = wt[0]+1 ; j <= capacity ; j++) ans[0][j] = ans[0][j-wt[0]]+val[0];
        for (int i = 1 ; i < n ; i++){
            for (int j = 0 ; j <= capacity ; j++){
                if (j >= wt[i]) ans[i][j] = max(ans[i-1][j] , ans[i][j-wt[i]]+val[i]);
                else ans[i][j] = ans[i-1][j];
            }
        }
        return ans[n-1][capacity];
    }
};

// space optimized

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<int> ans(capacity+1,0);
        if (wt[0] <= capacity) ans[wt[0]] = val[0];
        for (int j = wt[0]+1 ; j <= capacity ; j++) ans[j] = ans[j-wt[0]]+val[0];
        for (int i = 1 ; i < n ; i++){
            for (int j = wt[i] ; j <= capacity ; j++){
                ans[j] = max(ans[j] , ans[j-wt[i]]+val[i]);
            }
        }
        return ans[capacity];
    }
};