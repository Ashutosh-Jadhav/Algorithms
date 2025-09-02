class Solution {
public:
    int atmost(vector<int>& nums , int k) {
        if (k <= 0) return 0;
        int n,l,c; n = nums.size(); l = 0 ; c = 0;
        unordered_map<int,int> um;
        for (int i = 0 ; i < n ; i++) {
            um[nums[i]]++;
            if (um[nums[i]] == 1) k--;
            while (k < 0) {
                um[nums[l]]--;
                if(!um[nums[l]]) {k++;}
                l++;
            }
            c += i-l+1;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int c;
        c = atmost(nums,k) - atmost(nums,k-1);
        // cout << atmost(nums,k) << " " << atmost(nums,k-1);
        return c;
    }
};