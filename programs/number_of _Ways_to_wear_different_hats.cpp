// recursive

class Solution {
public:
    int func(int hat,int assigned_count, vector<vector<int>>& hat_to_people,int n, vector<int>& assigned) {
        const int m = 1e9+7;
        if (assigned_count == n) return 1;
        if (hat > 40) return 0;
        int ways = func(hat+1,assigned_count,hat_to_people,n,assigned)%m;
        for (int i = 0 ; i < hat_to_people[hat].size() ; i++) {
                if (!assigned[hat_to_people[hat][i]]){
                assigned[hat_to_people[hat][i]] = 1;
                ways += func(hat+1,assigned_count+1,hat_to_people,n,assigned)%m;
                assigned[hat_to_people[hat][i]] = 0;
            }
        }
        return ways%m;
    }
    int numberWays(vector<vector<int>>& hats) {
        // number of hats is fixed to 40
        const int m = 1e9+7;
        int n = hats.size();
        vector<vector<int>> hat_to_people(41);
        vector<int> assigned(n,0);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < hats[i].size() ; j++) {
                hat_to_people[hats[i][j]].push_back(i);
            }
        }
        int ways = func(1,0,hat_to_people,n,assigned)%m;
        return ways%m;
    }
};

// dp with bit mask

class Solution {
public:
    const long long m = 1e9+7;
    long long func(int hat, int mask , vector<vector<int>>& hats_to_people ,vector<vector<long long>>& dp,int n) {
        if (mask == (1 << n) -1) return 1;
        if (hat > 40) return 0;
        if (dp[hat][mask] != -1) return dp[hat][mask];
        long long ways;
        ways = func(hat+1,mask,hats_to_people,dp,n)%m;
        for (auto person : hats_to_people[hat]) {
            if ((mask & (1 << person)) == 0) {
                ways += func(hat+1,mask | (1 << person),hats_to_people,dp,n)%m;
            }
        }
        return dp[hat][mask] = ways%m;
    }
    int numberWays(vector<vector<int>>& hats) {
        int n; n = hats.size();
        vector<vector<int>> hats_to_people(41);
        vector<vector<long long>> dp(41,vector<long long>((1 << n),-1));
        for (int i = 0 ; i < n ; i++) {
            for (auto cap : hats[i]) {
                hats_to_people[cap].push_back(i);
            }
        }
        dp[1][0] = func(1,0,hats_to_people,dp,n)%m;
        return dp[1][0]%m;
    }
};