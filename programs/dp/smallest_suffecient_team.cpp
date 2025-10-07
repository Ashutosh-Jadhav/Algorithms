class Solution {
public:
    const int INF = 1e9;
    int func(int i , int mask, vector<int>& people_mask, int n, int m,vector<vector<int>>& dp, vector<vector<int>>& choice) {
        if (mask == (1 << n)-1) return 0;
        if (i == m) return INF;               // base case
        if (dp[i][mask] != -1) return dp[i][mask];
        
        int res = func(i+1,mask,people_mask,n,m,dp,choice);     // skip person i
        choice[i][mask] = 0;                         // save decision

        int take = 1+func(i+1,mask | people_mask[i],people_mask,n,m,dp,choice);
        if (take < res) {
            res = take;
            choice[i][mask] = 1;             // choosing person gives min
        }
        return dp[i][mask] = res;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n,m,mask; n = req_skills.size(); m = people.size();
        vector<int> people_mask(m);
        vector<int> ans;
        vector<vector<int>> choice(m+1, vector<int>(1 << n,-1));
        vector<vector<int>> dp(m+1,vector<int>(1 << n,-1));
        unordered_map<string,int> um;
        for (int i = 0; i < n ; i++) {
            um[req_skills[i]] = i;
        }
        for (int i = 0 ; i < m ; i++) {
            mask = 0;
            for (auto skill : people[i]) {
                mask = mask | (1 << um[skill]);
            }
            people_mask[i] = mask;
        }
        mask = 0;
        func(0,0,people_mask,n,m,dp,choice);
        for (int i = 0 ; i < m ; i++) {
            if (choice[i][mask] == 1) {
                ans.push_back(i);
                mask = mask | people_mask[i];        // skills added
            }
        }
        return ans;
    }
};