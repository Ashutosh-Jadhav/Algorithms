class Solution {
public:
    int numberOfSubstrings(string s) {
        int l_a,l_b,l_c,n,ans,m; l_a = -1 ; l_b = -1 ; l_c = -1; n = s.size(); ans = 0;
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == 'a') l_a = i;
            else if(s[i] == 'b') l_b = i;
            else l_c = i;
            if (l_a != -1 && l_b != -1 && l_c != -1) {
                m = min(l_a,l_b);
                ans += min(m,l_c)+1;
            }
        }
        return ans;
    }
};