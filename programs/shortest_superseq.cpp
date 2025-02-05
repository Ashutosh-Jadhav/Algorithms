class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m,n;
        m = str1.size();
        n = str2.size();
        int l , r ;
        string s;
        vector<vector<int>> ans(m+1,vector<int> (n+1,0));
        for (int i = 1 ; i <= m ; i++){
            for (int j = 1 ; j <= n ; j++){
                if (str1[i-1] == str2[j-1]) ans[i][j] = 1+ans[i-1][j-1];
                else ans[i][j]= max(ans[i-1][j],ans[i][j-1]);
            }
        }
        l = m; r = n ;
        while(l>0 && r>0){
            if (str1[l-1] == str2[r-1] && ans[l][r] == 1+ans[l-1][r-1]) {s = s + str1[l-1];l--;r--;}
            else if (ans[l][r-1] > ans[l-1][r]) {s = s+str2[r-1];r--;}
            else {l--;s = s+str1[l];}
        }
        while(l>0) s = s+ str1[--l];
        while(r>0) s = s+ str2[--r];
        reverse(s.begin() , s.end());
        return s;
    }
};