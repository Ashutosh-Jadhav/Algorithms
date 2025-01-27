class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n , m ,max = 0;
        n = s1.size();
        m = s2.size();
        vector<vector<int>>ans(n+1,vector<int>(m+1,0));
        for (int i = 1 ; i <= n ; i++ ){
            for (int j = 1 ; j <= m ; j++){
                if (s1[i-1] == s2[j-1]) ans[i][j] = 1 + ans[i-1][j-1] ;
                else ans[i][j] = 0 ;
                if (ans[i][j] > max) max = ans[i][j] ;
            }
        }
        return max ;
    }
};

// space optimized : space :- theta(min(n,m)) 

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n , m , temp ,max = 0;
        string temp_string;
        n = s1.size();
        m = s2.size();
        if (n > m) {temp = n ; n = m ; m = temp; temp_string = s1 ; s1 = s2 ; s2 = temp_string;}
        vector<vector<int>>ans(2,vector<int>(m+1,0));
        for (int i = 1 ; i <= n ; i++ ){
            for (int j = 1 ; j <= m ; j++){
                if (s1[i-1] == s2[j-1]) ans[i%2][j] = 1 + ans[(i-1)%2][j-1] ;
                else ans[i%2][j] = 0 ;
                if (ans[i%2][j] > max) max = ans[i%2][j] ;
            }
        }
        return max ;
    }
};