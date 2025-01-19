// Memoization (Top Down)

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int m = arr.size();
        vector<vector<int>> ans(m, vector<int>(target+1, -1));
        if (target == 0 )
        {
            return true;
        }
        return f(0,target,arr,ans);
    }
    int f(int i , int target, vector<int>& arr, vector<vector<int>>& ans)
    {
        if(target == 0 ){
            return 1 ;
        }
        if(i == arr.size()){
            return 0;
        }
        if(ans[i][target] != -1)
        {
            return ans[i][target];
        }
        if (target < arr[i]){
            return ans[i][target] = f(i+1,target,arr,ans);
        }
        else return ans[i][target] = max(f(i+1,target - arr[i], arr,ans),f(i+1,target,arr,ans));
        
    }
};


// tabulation with space optimized (Bottom Up)

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int m = arr.size();
        vector<vector<int>> ans(2, vector<int>(target+1, 0));
        if (target == 0 )
        {
            return true;
        }
        for(int i = 0 ; i < 2 ; i++){
            ans[i][0] = 1;
        }
        for (int j = 0 ; j < target+1 ; j++){
            if (arr[0] == j && arr[0] < target){
                ans[0][j] = 1;
            }
        }
        for (int i = 1 ; i < m ; i++){
            for (int j = 1 ; j < target+1 ; j++){
                if (j - arr[i] >=0){
                    ans[i%2][j] = max(ans[(i-1)%2][j],ans[(i-1)%2][j-arr[i]]);
                }
                else {
                    ans[i%2][j] = ans[(i-1)%2][j];
                }
            }
        }
        return ans[(m-1)%2][target];
    }
};
