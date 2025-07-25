// Brute force

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),c=0,max_len=0;
        unordered_set<char> us;
        for (int i = 0 ; i < n ; i++) {
            for (int j = i ; j < n ; j++) {
                // substring from i to j
                for (int k = 0 ; k < j-i+1 ; k++) {
                    auto m = us.find(s[i+k]);
                    if (m != us.end()) break;
                    us.insert(s[i+k]); c++;
                }
                us.clear();
                if (c > max_len) max_len = c;
                c = 0;
            }
        }
        return max_len;
    }
};

// we can do better

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),max_len=0,flag = 0,j=0;
        unordered_set<char> us;
        for (int i = 0 ; i < n ; i++) {
            auto m = us.find(s[i]);
            if (m != us.end()) {
                if (max_len < i-j) max_len = i-j;
                while(s[j] != s[i]) {us.erase(s[j]);j++;}j++;
            }
            else {us.insert(s[i]);if(max_len < i-j+1) max_len = i-j+1;}
        }
        return max_len;
    }
};