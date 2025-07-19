class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = 0 ,ans=0;
        for (int i = 1 ; i < nums.size() ; i++) {
            if (nums[min] > nums[i]) min = i ;
        }
        for (int i = 0 ; i < nums.size() ; i++) {
            ans += nums[i] - nums[min];
        }
        return ans;
    }
};