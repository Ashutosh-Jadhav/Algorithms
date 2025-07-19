// first approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); int ans = 0 ;
        vector<int> next_l(n,-1); stack<int> s ; vector<int> n_l_l(n,-1);
        for (int i = 0 ; i < n ; i++) {
            while (!s.empty() && height[s.top()] < height[i]) {next_l[s.top()] = i ; s.pop();}
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 0 ; i < n ; i++) {
            while (!s.empty() && height[s.top()] < height[n-i-1]) {n_l_l[s.top()] = n-i-1; s.pop();}
            s.push(n-i-1);
        }
        while(!s.empty()) s.pop();
        for (int i = 0  ; i < n ; i++) {
            while (!s.empty() && next_l[i] == -1) {next_l[s.top()] = i; s.pop();}
            if (next_l[i] != -1) s.push(i);
        }
        for (int i = 0 ; i < n ; i++) {
            while (!s.empty() && n_l_l[n-i-1] == -1) {n_l_l[s.top()] = n-i-1; s.pop();}
            if (n_l_l[n-i-1] != -1) s.push(n-i-1);
        }
        for (int i = 0 ; i < n ; i++) {
            if (n_l_l[i] == -1 || next_l[i] == -1) continue;
            ans = ans + min(height[n_l_l[i]],height[next_l[i]]) - height[i];
        }
        return ans;
    }
};


// improved

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); int ans = 0 ;
        vector<int> prefix(n,0); vector<int> suffix(n,0);
        prefix[0] = height[0]; suffix[n-1] = height[n-1];
        for (int i = 1 ; i < n ; i++) {
            prefix[i] = max(prefix[i-1],height[i]);
            suffix[n-i-1] = max(suffix[n-i],height[n-i-1]);
        }
        for (int i  = 0 ; i < n ; i++) {
            ans = ans+ min(prefix[i],suffix[i]) -height[i];
        }
        return ans;
    }
};

// space optimized

class Solution {
public:
    int trap(vector<int>& height) {
        int left_max, right_max , l , r,n,ans=0; n = height.size();
        l = 0 ; r = n-1 ; left_max = height[0]; right_max = height[n-1];
        while (l < r) {
            if (height[l] > height[r]) {
                if (height[r] > right_max) right_max = height[r];
                else {ans += right_max-height[r] ; r--;}
            }
            else {
                if (height[l] > left_max) left_max = height[l];
                else {ans += left_max - height[l]; l++;}
            }
        }
        return ans;
    }
};