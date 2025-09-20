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