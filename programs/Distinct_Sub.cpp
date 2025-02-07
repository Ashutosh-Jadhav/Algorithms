// Bottom Up

class Solution {
    public:
        int numDistinct(string s, string t) {
            int n,m,res,i1,j1;
            unsigned long long c = 0 ;
            m = s.size();
            n = t.size();
            vector<vector<int>> ans(m+1,vector<int> (n+1,0));
            vector<vector<unsigned long long>> nums(m+1,vector<unsigned long long> (n+1,1));
            i1 = m ; 
            j1 = n ;
            while (i1 > 0 && j1 > 0){
                if (s[i1-1] == t[j1-1]) {i1--;j1--;}
                else i1--;
            }
            if (j1 != 0 ) return 0;
    
            for (int i = 1 ; i <= m ; i++){
                for (int j = 1 ; j <= n ;j++){
                    if (s[i-1] == t[j-1]) {
                        c = 0;
                        ans[i][j] = 1 + ans[i-1][j-1];
                        if (ans[i][j] == ans[i-1][j]) c = nums[i-1][j];
                        if (ans[i][j] == ans[i][j-1]) c+= nums[i][j-1];
                        nums[i][j] = c + nums[i-1][j-1];
                    }
                    else {
                        ans[i][j] = max(ans[i-1][j] , ans[i][j-1]);
                        if (ans[i-1][j] > ans[i][j-1]) nums[i][j] = nums[i-1][j];
                        else if (ans[i][j-1] > ans[i-1][j]) nums[i][j] = nums[i][j-1];
                        else nums[i][j] = nums[i-1][j] + nums[i][j-1];
                    }
                }
            }
    
            return nums[m][n];
        }
    };


// Space Optimized Bottom Up 

class Solution {
    public:
        int numDistinct(string s, string t) {
            int n,m,res,i1,j1;
            unsigned long long c = 0 ;
            m = s.size();
            n = t.size();
            vector<vector<int>> ans(2,vector<int> (n+1,0));
            vector<vector<unsigned long long>> nums(2,vector<unsigned long long> (n+1,1));
            i1 = m ; 
            j1 = n ;
            while (i1 > 0 && j1 > 0){
                if (s[i1-1] == t[j1-1]) {i1--;j1--;}
                else i1--;
            }
            if (j1 != 0 ) return 0;        // String Not available in s
    
            // for (int j  = 1 ; j<= n ; j++) nums[0][j] = 0;
    
            for (int i = 1 ; i <= m ; i++){
                for (int j = 1 ; j <= n ;j++){
                    c = 0;
                    if (s[i-1] == t[j-1]) {
                        ans[i%2][j] = 1 + ans[(i-1)%2][j-1];
                        if (ans[i%2][j] == ans[(i-1)%2][j]) c = nums[(i-1)%2][j];
                        if (ans[i%2][j] == ans[i%2][j-1]) c+= nums[i%2][j-1];
                        nums[i%2][j] = c + nums[(i-1)%2][j-1];
                    }
                    else {
                        ans[i%2][j] = max(ans[(i-1)%2][j] , ans[i%2][j-1]);
                        if (ans[(i-1)%2][j] > ans[i%2][j-1]) nums[i%2][j] = nums[(i-1)%2][j];
                        else if (ans[i%2][j-1] > ans[(i-1)%2][j]) nums[i%2][j] = nums[i%2][j-1];
                        else nums[i%2][j] = nums[(i-1)%2][j] + nums[i%2][j-1];
                    }
                }
            }
    
            return nums[m%2][n];
        }
    };

// Backtracking but gives TLE, good code though


int count(int i , int j ,string s , string t , vector<vector<int>>& ans){
    int c = 0 ;
    if (i < 1 || j < 1) return 1 ;
    if (s[i-1] == t[j-1]){
        if (ans[i][j] == ans[i-1][j]) c += count(i-1,j,s,t,ans);
        if (ans[i][j] == ans[i][j-1]) c+= count(i,j-1,s,t,ans);
        return c+count(i-1,j-1,s,t,ans);
    }
    else{
        if (ans[i-1][j] > ans[i][j-1]) return count(i-1,j,s,t,ans);
        else if(ans[i][j-1] > ans[i-1][j]) return count(i,j-1,s,t,ans);
        else return count(i,j-1,s,t,ans)+count(i-1,j,s,t,ans);
    }
}

int numDistinct(string s, string t) {
    int n,m,res;
    m = s.size();
    n = t.size();
    vector<vector<int>> ans(m+1,vector<int> (n+1,0));
    for (int i = 1 ; i <= m ; i++){
        for (int j = 1 ; j <= n ;j++){
            if (s[i-1] == t[j-1]) ans[i][j] = 1 + ans[i-1][j-1];
            else ans[i][j] = max(ans[i-1][j] , ans[i][j-1]);
        }
    }
    if (ans[m][n] < t.size()) return 0 ;
    return count(m,n,s,t,ans);
}

