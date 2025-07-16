class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n,m;
        m = nums2.size();
        n = nums1.size();
        vector<int> ans(n,-1);
        stack<int> s;
        unordered_map<int,int> um;
        for (int i = 0 ; i < n ; i++) {
            um.insert({nums1[i],i});
        }
        for (int i = 0 ; i < m ;i++) {
            while(!s.empty() && nums2[i] > s.top()) {ans[um[s.top()]] = nums2[i];s.pop();}
            auto it = um.find(nums2[i]);
            if (it != um.end()) s.push(nums2[i]);
        }
        return ans;
    }
};