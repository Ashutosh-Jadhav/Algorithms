class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int n,m,mask,c,ma=0; m = seats.size(); n = seats[0].size();
        vector<vector<int>> valid_masks(m);
        vector<int> rows(m,0);
        vector<vector<int>> dp(m,vector<int>(1 << n, 0));
        for (int i = 0 ; i < m ; i++) {
            mask = 0;
            for (int j = 0 ; j < n ; j++) {
                if (seats[i][j] == '.') mask = mask | (1 << j);
            }
            rows[i] = mask;
        }
        for (int i = 0 ; i < m ; i++) {
            vector<int> valid;
            for (mask = 0 ; mask < (1 << n) ; mask++) {
                if ((mask & ~rows[i]) != 0) continue;            //broken seats
                if ((mask & (mask << 1)) != 0) continue;         // student sitting next to each other
                valid.push_back(mask);
            }
            valid_masks[i] = valid;
        }
        // base case
        for (auto mask : valid_masks[0]) {
            dp[0][mask] = __builtin_popcount(mask);
            if (0 == m-1) if (ma < dp[0][mask]) ma = dp[0][mask];
        }
        for (int i = 1 ; i < m ; i++) {
            for (auto mask : valid_masks[i]) {
                c = __builtin_popcount(mask);
                for (auto prev : valid_masks[i-1]) {
                    if ((prev & (mask >> 1)) == 0 && (prev & (mask << 1)) == 0) {
                        dp[i][mask] = max(dp[i-1][prev]+c,dp[i][mask]);
                    }
                }
                if (i == m-1) if (ma < dp[i][mask]) ma = dp[i][mask];
            }
        }
        return ma;
    }
};


// Space Optimized

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int n,m,mask,c,ma=0; m = seats.size(); n = seats[0].size();
        // vector<vector<int>> valid_masks(m);
        vector<int> rows(m,0);
        vector<vector<int>> dp(2,vector<int>(1 << n, 0));
        for (int i = 0 ; i < m ; i++) {
            mask = 0;
            for (int j = 0 ; j < n ; j++) {
                if (seats[i][j] == '.') mask = mask | (1 << j);
            }
            rows[i] = mask;
        }
        // base case
        for (mask = 0 ; mask < (1 << n) ; mask++) {
            if ((mask & ~rows[0]) != 0) continue;
            if ((mask & (mask << 1)) != 0) continue;
            dp[0][mask] = __builtin_popcount(mask);
            if (0 == m-1) if (ma < dp[0][mask]) ma = dp[0][mask];
        }
        for (int i = 1 ; i < m ; i++) {
            for (mask = 0 ; mask < (1 << n) ; mask++) {
                if ((mask & ~rows[i]) != 0) continue;
                if ((mask & (mask << 1)) != 0) continue;
                c = __builtin_popcount(mask);
                for (int prev = 0 ; prev < (1 << n) ; prev++) {
                    if ((prev & ~rows[i-1]) != 0) continue;
                    if ((prev & (prev << 1)) != 0) continue;
                    if ((prev & (mask >> 1)) == 0 && (prev & (mask << 1)) == 0) {
                        dp[i%2][mask] = max(dp[(i-1)%2][prev]+c,dp[i%2][mask]);
                    }
                }
                if (i == m-1) if (ma < dp[i%2][mask]) ma = dp[i%2][mask];
            }
        }
        return ma;
    }
};