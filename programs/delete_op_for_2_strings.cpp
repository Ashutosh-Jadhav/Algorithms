// Bottom Up

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>ans(n+1,vector<int> (m+1,0));
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <=m ; j++){
                if (word1[i-1] == word2[j-1]) ans[i][j] = 1+ans[i-1][j-1];
                else ans[i][j] = max(ans[i-1][j] , ans[i][j-1]);
            }
        }
        return m + n - 2*ans[n][m] ;
    }
};

// Space Optimized

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>ans(2,vector<int> (m+1,0));
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <=m ; j++){
                if (word1[i-1] == word2[j-1]) ans[i%2][j] = 1+ans[(i-1)%2][j-1];
                else ans[i%2][j] = max(ans[(i-1)%2][j] , ans[i%2][j-1]);
            }
        }
        return m + n - 2*ans[n%2][m] ;
    }
};