// Memoisation (Top Down)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> ans(n,vector<int> (n,-1));
        return f(0,n-1,s,ans);
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

// tabulation (Bottom Up)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> ans(n+1,vector<int> (n+1,0));
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= n ;j++){
                if(s[i-1] == s[n-j]) ans[i][j] = 1 + ans[i-1][j-1];
                else ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
            }
        }
        return ans[n][n];
    }
};

// Space optimized

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> ans(2,vector<int> (n+1,0));
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= n ;j++){
                if(s[i-1] == s[n-j]) ans[i%2][j] = 1 + ans[(i-1)%2][j-1];
                else ans[i%2][j] = max(ans[(i-1)%2][j],ans[i%2][j-1]);
            }
        }
        return ans[n%2][n];
    }
};

// not working code , login seems correct want to find what is the problem
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int m = 1 , l =1 ,r = 1,l1,r1 ;
        vector<vector<int>> ans(n+1,vector<int> (n+1,0));
        for (int i = 1 ; i <= n ; i++){
            for (int j = 1 ; j <= n ;j++){
                if (j >= n-i+1){
                    break;
                }
                else if(s[i-1] == s[n-j]) ans[i][j] = 2 + ans[i-1][j-1];
                else ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
                if (ans[i][j] > m) {
                    m = ans[i][j];
                    l = i ;
                    r = j ;
                }
            }
        }
        for (int i = 1 ; i < n+1 ; i++){
            for (int j = 1 ; j < n+1 ; j++){
                cout << ans[i][j] << " ";
            }
            cout <<endl;
        }
        cout << l << " " << r << " " << endl ;
        cout << s.substr(0,l) << s.substr(n-r,n-1) << endl ;
        l1 = l ; r1 = r;
        while ( l > 0 && r > 0 && s[l-1] == s[n-r] ) {
            l--;
            r--;
        }
        cout << l << " " << r << endl;
        if (l == 0 || r == 0 ) m++;
        else if(l1+r1 < n && m > 1) m++;

        return m;
    }
};
// "cdarzowkkycdarzowkkycdarzowkkycdarzowkkycdarzowkkycdarzowkkycdarzowkkycdarzowkkycdarzowkkycdarzowkky"