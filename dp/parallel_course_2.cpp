class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        const int INF = 1e9;
        int u,v,c;
        vector<int> dp(1 << n,INF);
        vector<int> prereq(n,0);
        for (int i = 0 ; i < relations.size() ; i++) {
            u = relations[i][0] -1 ;
            v = relations[i][1] - 1;
            prereq[v] = prereq[v] | (1 << u);           // ith bit 1
        }
        dp[0] = 0;      
        for (int mask = 0 ; mask < (1 << n); mask++) {
            if (dp[mask] == INF) continue;
            int can = 0;
            for (int i = 0 ; i < n ;i++) {
                if (!(mask & (1 << i)) && (prereq[i] & mask) == prereq[i]) {
                    can = can | (1 << i);
                }
            }
            if (can == 0) continue;
            c = __builtin_popcount(can);
            if (c <= k) {
                dp[mask|can] = min(dp[mask|can],dp[mask]+1);
            }
            else {
                for (int sub = can ; sub > 0 ; sub = (sub-1) & can) {
                    c = __builtin_popcount(sub);
                    if (c <= k) {
                        dp[mask|sub] = min(dp[mask|sub],dp[mask]+1);
                    }
                }
            }
        }
        return dp[(1<<n)-1];
    }
};