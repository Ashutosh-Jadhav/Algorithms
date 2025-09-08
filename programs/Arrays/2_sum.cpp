// using hashing

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        int n = nums.size();
        for (int i = 0 ; i < n ; i++) {
            um.insert({nums[i],i});
            auto m = um.find(target-nums[i]);
            if (m != um.end() && m->second != i) return {i,m->second};
        }
        return {};
    }
};

// sorting and 2 pointer

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n,l,r; n = nums.size(); l = 0 ; r = 1 ;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        while (l < n && r < n ) {
            if (nums[l] + nums[r] == target) {
                return {l,r};
            }
            if (nums[l] + nums[r] > target) {
                l++;
            }
            else r++;
        }
        return ans;
    }
};