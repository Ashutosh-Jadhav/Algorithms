class Solution {
public:
    int at_most(vector<int>& nums, int k) {
        // if (k < 0) return 0;
        int c,n,curr,l; n = nums.size(); curr = 0 ; c = 0 ; l = 0;
        for (int r = 0 ; r < n ; r++) {
            if (nums[r]%2 == 1) curr++;
            while(curr > k) {
                if(nums[l]%2 == 1) curr--;
                l++;
            }
            c += r-l+1;
        }
        return c;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int c;
        c = at_most(nums,k) - at_most(nums,k-1);
        return c;
    }
};