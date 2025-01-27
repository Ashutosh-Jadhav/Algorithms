// Bottom Up

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>ans (n+1,vector<int>(n+1,0));
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= n ; j++){
                if (s[i-1] == s[n-j]) ans[i][j] = 1+ans[i-1][j-1];
                else ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
            }
        }
        cout << ans[n][n] << endl;
        return n - ans[n][n];
    }
};

// Space Optimized

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>ans (2,vector<int>(n+1,0));
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= n ; j++){
                if (s[i-1] == s[n-j]) ans[i%2][j] = 1+ans[(i-1)%2][j-1];
                else ans[i%2][j] = max(ans[(i-1)%2][j],ans[i%2][j-1]);
            }
        }
        cout << ans[n%2][n] << endl;
        return n - ans[n%2][n];
    }
};

// memoization (top down)

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> ans(n,vector<int> (n,-1));
        return n-f(0,n-1,s,ans);
    }
    int f(int i , int j , string &s,vector<vector<int>>& ans)
    {
        if (i == j ) return 1 ;
        if (i > j || i>s.size()-1 || j < 0) return 0 ;
        if (ans[i][j] != -1) return ans[i][j];
        if (s[i] == s[j]) return ans[i][j] = 2+f(i+1,j-1,s,ans);
        return ans[i][j] = max(f(i+1,j,s,ans) , f(i,j-1,s,ans));
    }
};