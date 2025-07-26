class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_len=0,t=k,n=nums.size(),left=0;
        for (int right = 0 ; right < n ; right++) {
            if (nums[right]==1) {if(max_len < right-left+1) max_len = right-left+1;}
            else {
                if(t) {if(max_len < right-left+1) max_len = right-left+1;t--;}
                else {
                    if (right-left > max_len) max_len = right-left;
                    while(nums[left]) left++;
                    left++;
                }
            }
        }
        return max_len;
    }
};

// clean code

