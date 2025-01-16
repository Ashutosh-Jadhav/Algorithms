class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count_0 = 0;
        int sum = 0 ;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] < 0) sum += nums[i]*(-1);
            else sum += nums[i];
            if (nums[i] == 0) {
                count_0++;
                nums.erase(nums.begin()+i);
                i--;
                if(nums.empty()) break;
            }
        }
        int n = nums.size();
        if (n == 0) return pow(2,count_0);
        vector<vector<int>> ans(nums.size(),vector<int> (2001,0));

        ans[n-1][sum+1000] = 1; ans[n-1][(-1)*sum+1000] = 1;
        ans[0][nums[0]+1000] = 1 ; ans[0][(-1)*nums[0]+1000] = 1 ;

        for (int i = 1 ; i < nums.size() ; i++){
            for (int j = 0 ; j < 2000 ; j++){
                if (j-nums[i] < 0 && j+nums[i] < 2001) ans[i][j] = ans[i-1][j+nums[i]] ;
                else if(j - nums[i] > 0 && j+nums[i] > 2001) ans[i][j] = ans[i-1][j-nums[i]] ;
                else if(j-nums[i] > 0 && j+nums[i] < 2001) ans[i][j] = ans[i-1][j-nums[i]] + ans[i-1][j+nums[i]] ;
            }
        }
        // if (target == 0) return ans[n-1][target+1000]*pow(2,count_0);
        cout << ans[n-1][target+1000] << " " << count_0 << endl;
        return ans[n-1][target+1000]*pow(2,count_0);
    }
};