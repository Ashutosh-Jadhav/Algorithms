// O(n^2)

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n,c,ans; n = s.size(); c = 0; ans  = 0;
        vector<int> num(n+1,0);
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == '0') c--;
            else c++;
            num[i+1] = c;
        }
        int mid,l=0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = i+1 ; j < n ; j=j+2) {
                if (num[i] == num[j+1]) {
                    mid = (j-i+1)/2;
                    if (num[i+mid] == num[i]+mid || num[i+mid] == num[i]-mid) {ans++;}
                }
            }
        }
        return ans;
    }
};

// Optimized

