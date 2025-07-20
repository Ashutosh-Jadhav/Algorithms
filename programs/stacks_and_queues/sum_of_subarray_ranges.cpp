class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size(); long long largest = 0, smallest = 0;
        vector<int> n_l_r(n,n) , n_l_l(n,-1) , n_s_r(n,n) ,n_s_l(n,-1);
        stack<int> s1; stack<int> s2;
        for (int i = 0 ; i < n ; i++) {
            while (!s1.empty() && nums[s1.top()] <= nums[i]) {n_l_r[s1.top()] = i;s1.pop();}
            while (!s2.empty() && nums[s2.top()] >= nums[i]) {n_s_r[s2.top()] = i;s2.pop();}
            s2.push(i);
            s1.push(i);
        }
        while (!s1.empty()) s1.pop(); while (!s2.empty()) s2.pop();
        for (int i = 0 ; i < n ; i++) {
            while (!s1.empty() && nums[s1.top()] < nums[n-i-1]) {n_l_l[s1.top()] = n-i-1; s1.pop();}
            while (!s2.empty() && nums[s2.top()] > nums[n-i-1]) {n_s_l[s2.top()] = n-i-1; s2.pop();}
            s1.push(n-i-1); s2.push(n-i-1);
        }
        for (int i = 0 ; i < n ; i++) {
            largest = largest + (1LL*i-n_l_l[i])*nums[i]*(n_l_r[i]-i);
            smallest = smallest + (1LL*i-n_s_l[i])*nums[i]*(n_s_r[i]-i);
            largest = largest -smallest; smallest = 0;
        }
        return largest;
    }
};