// first approach
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n  = s.size(),left = 0,max_len = 0,m=0,count=0; if (k >= n ) return n;
        vector<char> alph = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        unordered_map<char,int> um;
        for (int i = 0 ; i < alph.size() ; i++) {
            um.insert({alph[i],0});
        }
        for (int right = 0 ; right < n ; right++) {
            um[s[right]]++; count=0;
            for (int i = 0 ; i < 26 ; i++) {
                count = count + um[alph[i]];
                if (m < um[alph[i]]) m = um[alph[i]];
            }
            count = count - m; m = 0;
            if (count <= k) {if (max_len < right-left+1) max_len = right-left+1;}
            else {um[s[left]]--;left++;}
        }
        return max_len;
    }
};

// improved code

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); if (k >= n ) return n;
        vector<int> freq(26,0);                  // take a as base ascii value relatively all till Z will fall in 1 to 25
        int max_freq=0,max_len = 0,left=0;
        for (int right=0;right < n ; right++) {
            freq[s[right] - 'A']++;
            max_freq = max(max_freq,freq[s[right] - 'A']); // total elements in window = right-left+1
            while (k < (right-left+1)-max_freq){
                freq[s[left] - 'A']--;left++;
            }
            if (max_len < right-left+1) max_len = right-left+1;
        }
        return max_len;
    }
};