// top down with memory optimization

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int count=0,tot_sum=0,target;
        for (int i = 0 ; i < arr.size() ; i++){
            tot_sum += arr[i] ;
            if(arr[i] == 0){
                count++;
                arr.erase(arr.begin()+i);
                i--;
            }
        }
        target = (d+tot_sum)/2 ;
        // cout << target << endl << tot_sum << endl;
        if((d+tot_sum)%2 != 0 ) return 0;
        if (target == 0)
            return pow(2,count);
        
        vector<vector<int>> ans(2,vector<int>(target+1,0));
        ans[0][0] = 1 ; ans[1][0] = 1 ;
        if (arr[0] <= target) ans[0][arr[0]] = 1;
        
        for(int i = 1 ; i < arr.size() ; i++){
            for(int j = 1 ; j <= target ; j++){
                if (arr[i] <= j)
                    ans[i%2][j] = ans[(i-1)%2][j] + ans[(i-1)%2][j-arr[i]] ;
                else 
                    ans[i%2][j] = ans[(i-1)%2][j] ;
            }
        }
        return ans[(arr.size()-1)%2][target]*pow(2,count);
    }
};