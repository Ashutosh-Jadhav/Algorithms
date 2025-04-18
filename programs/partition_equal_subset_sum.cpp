// memoization (Top Down)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n,m, tot_sum = 0 ;
        m = nums.size();
        for (int i = 0 ; i < m ; i++){
            tot_sum += nums[i];
        }
        if(tot_sum%2 != 0){
            return false;                     // commenting this will give runtime, isnt that intersting (dont know why)
        }
        n = tot_sum / 2 ;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        return f(0,0,nums,ans,tot_sum);
    }
    bool f(int i , int sum , vector<int>& nums , vector<vector<int>>& ans,int tot_sum) {
        if (2*sum == tot_sum){
            return 1 ;
        }
        if (sum > tot_sum/2){
            return 0 ;
        }
        if (i == nums.size()){
            return 0 ; 
        }
        if (ans[i][sum] != -1){
            return ans[i][sum];
        }
        return ans[i][sum]=max(f(i+1,sum+nums[i],nums,ans,tot_sum),f(i+1,sum,nums,ans,tot_sum));
        // return ans[i][sum]=f(i+1,sum+nums[i],nums,ans,tot_sum) || f(i+1,sum,nums,ans,tot_sum) ;
    }
};


// Bottom Up

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n,m, tot_sum = 0 ;
        m = nums.size();
        for (int i = 0 ; i < m ; i++){
            tot_sum += nums[i];
        }
        if(tot_sum%2 != 0){
            return false;
        }
        n = tot_sum / 2 ;
        int target = n ;
        vector<vector<int>> ans(2, vector<int>(n+1, 0));
        for(int i = 0 ; i < 2 ; i++){
            ans[i][0] = 1;
        }
        for (int j = 0 ; j < target+1 ; j++){
            if (nums[0] == j && nums[0] < target){
                ans[0][j] = 1;
            }
        }
        for (int i = 1 ; i < m ; i++){
            for (int j = 1 ; j < target+1 ; j++){
                if (j - nums[i] >=0){
                    ans[i%2][j] = max(ans[(i-1)%2][j],ans[(i-1)%2][j-nums[i]]);
                }
                else {
                    ans[i%2][j] = ans[(i-1)%2][j];
                }
            }
        }
        return ans[(m-1)%2][target];
    }
};

