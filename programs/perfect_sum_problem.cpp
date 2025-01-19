// working BottomUp

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int count = 0 ;
        for (int i = 0 ; i < arr.size() ; i++){
            if (arr[i] == 0){
                count++;
                arr.erase(arr.begin()+i);
                i--;
            }
        }
        if (target == 0 )
            return pow(2,count);
        vector<vector<int>> ans(2,vector<int>(target+1,0));   // we need target as an index
        for (int i = 0 ; i < 2 ; i++){
            ans[i][0] = 1 ;
        }
        if(arr[0] <= target){
            ans[0][arr[0]] = 1 ;
        }
        for (int i = 1 ; i < arr.size() ; i++){
            for (int j = 1 ; j <= target ; j++){
                if (arr[i] <= j)
                    ans[i%2][j] = ans[(i-1)%2][j] + ans[(i-1)%2][j-arr[i]] ;
                else
                    ans[i%2][j] = ans[(i-1)%2][j];
            }
        }
        return ans[(arr.size()-1)%2][target]*pow(2,count);
    }
};

// this code is not working on arr = 8 0 8 0 8 8   target = 8

public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int count =0;
        if (target == 0){
            for(int i = 0 ; i < arr.size() ; i++){
                if (arr[i] == 0)
                    count++;
            }
            return pow(2,count);
        }
        for (int i = 1 ; i < arr.size() ; i++){
            if (arr[i] == 0){
                count++;
            }
        }
        int ans = f(0,0,arr,target);
        // return ans ;
        return (pow(2,count)-1)*ans + ans;
    }
    int f(int i, int sum, vector<int>& arr,int target)
    {
        // if (sum == target && i < arr.size()){
        //     return 1;
        // }
        if (sum == target)
        {
            return 1;
        }
        if (i == arr.size() || sum > target){
            return 0;
        }
        if (i < arr.size()-1 && arr[i+1]==0 ){
            int j = i ;
            // i++;
            for (int k = i+1 ; k < arr.size() - 1  ; k++){
                if(arr[k] == 0 )
                    i++;
            }
            return f(i+1,sum+arr[j],arr,target) + f(i+1,sum,arr,target);
        }
        return f(i+1,sum+arr[i],arr,target) + f(i+1,sum,arr,target);
    }
