class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0,n = nums.size();
        vector<int> ans(n-k+1,0);
        deque<int> dq;
        for (int i = 0 ; i < k ; i++) {
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        for (int i = k ; i < n ; i++) {
            ans[l] = nums[dq.front()]; l++;
            if (dq.front() > l+k || dq.front()<l) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        ans[l] = nums[dq.front()];
        return ans;
    }
};