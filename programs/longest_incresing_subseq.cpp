// Simple recursion

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            return f(0,-10001,nums);
        }
        int f(int i , int maxi,vector<int>& nums){
            if (i >= nums.size()) return 0 ;
            if (nums[i] > maxi){
                return max(1+f(i+1,nums[i],nums) , f(i+1,maxi,nums));
            }
            return f(i+1,maxi,nums);
        }
    };

// bottom Up

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size(),maxi = 1;
            vector<vector<int>> ans(n+1,vector<int> (n+1,1));
            for (int i = n-1 ; i > 0 ; i--){
                for (int j = 0 ; j <= i ; j++){
                    if (nums[i] > nums[j]){
                        ans[i][j] = max(1+ ans[i+1][i] , ans[i+1][j]);
                    }
                    else ans[i][j] = ans[i+1][j];
                    if (maxi < ans[i][j]) maxi = ans[i][j];
                }
            }
            return maxi;
        }
    };

// Space optimized

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size(),maxi = 1;
            vector<vector<int>> ans(2,vector<int> (n+1,1));
            for (int i = n-1 ; i > 0 ; i--){
                for (int j = 0 ; j <= i ; j++){
                    if (nums[i] > nums[j]){
                        ans[i%2][j] = max(1+ ans[(i+1)%2][i] , ans[(i+1)%2][j]);
                    }
                    else ans[i%2][j] = ans[(i+1)%2][j];
                    if (maxi < ans[i%2][j]) maxi = ans[i%2][j];
                }
            }
            return maxi;
        }
    };

// Top Down

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            nums.insert(nums.begin()+0 , -10001);
            int n = nums.size();
            vector<vector<int>> ans(n+1,vector<int> (n+1,-1));
            return f(1,0,nums,ans);
        }
        int f(int i , int maxi,vector<int>& nums, vector<vector<int>>& ans){
            if (i >= nums.size()) return 0 ;
            if (ans[i][maxi] != -1) return ans[i][maxi];
            if (nums[i] > nums[maxi]){
                return ans[i][maxi] = max(1+f(i+1,i,nums,ans) , f(i+1,maxi,nums,ans));
            }
            return ans[i][maxi] = f(i+1,maxi,nums,ans);
        }
    };


// 2nd approach

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            int max = 0 , max1=0;
            vector<vector<int>> ans(n,vector<int> (n,0));
            for (int i = 0 ; i < n ; i++){
                max = 1 ;
                for (int j= 0 ; j < i+2 ; j++){
                    if (j == i) ans[i][j] = 1 ;
                    else if (j == i+1){
                        if (i == n-1) break;
                        ans[i][j] = max ;
                    }
                    else if (nums[i] > nums[j]) {
                        ans[i][j] = 1 + ans[j][j+1];
                        if (ans[i][j] > max) max = ans[i][j];
                    }
                    else ans[i][j] = ans[i-1][j];
                    // if (ans[i][j] > max) max = ans[i][j];
                    if (ans[i][j] > max1) max1 = ans[i][j];
                }
            }
            // for (int i = 0 ; i < n ; i++){
            //     for (int j= 0 ; j < n ; j++){
            //         cout << ans[i][j] ;
            //     }
            //     cout << endl;
            // }
            return max1;
        }
    };


