class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>ans (n,vector<int> (amount+1,0));
        vector<vector<int>>check (n,vector<int> (amount+1,-1));
        for(int i = 0 ; i< n ; i++){
            ans[i][0] = 1;
            check[i][0] = 1;
        }
        if (coins[0] <= amount) ans[0][coins[0]] = 1;
        for (int j = 1 ; j <= amount ; j++){
            if (j>=coins[0]) {
                ans[0][j] = ans[0][j-coins[0]];
                check[0][j] = check[0][j-coins[0]];
            }
        }
        for (int i = 1 ; i<n ; i++){
            for (int j = 1 ; j <= amount ;j++){
                if (j >= coins[i]) check[i][j] = max(check[i][j-coins[i]] , check[i-1][j]);
                else check[i][j] = check[i-1][j];
            }
        }
        if (check[n-1][amount] == -1) return 0;
        for (int i = 1 ; i<n ; i++){
            for (int j = 1 ; j <= amount ;j++){
                if (j >= coins[i]) ans[i][j] = ans[i][j-coins[i]] + ans[i-1][j];
                else ans[i][j] = ans[i-1][j];
            }
        }
        return ans[n-1][amount];
    }
};

// space optimized

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>ans (amount+1,0);
        vector<int>check (amount+1,-1);
        for(int i = 0 ; i< n ; i++){
            ans[0] = 1;
            check[0] = 1;
        }
        for (int j = coins[0] ; j <= amount ; j++){
            ans[j] += ans[j-coins[0]];
            check[j] = check[j-coins[0]];
        }
        for (int i = 1 ; i<n ; i++){
            for (int j = coins[i] ; j <= amount ;j++){
                check[j] = max(check[j-coins[i]] , check[j]);
            }
        }
        if (check[amount] == -1) return 0;
        for (int i = 1 ; i<n ; i++){
            for (int j = coins[i] ; j <= amount ;j++){
                ans[j] += ans[j-coins[i]];
            }
        }
        return ans[amount];
    }
};