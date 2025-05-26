// Bottom Up (Tabulation)

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size() - 1 ;
        int j,temp = 0 ;
        vector<vector<int>> ans(n+1, vector<int>(n+1,0));
        for (int len = 2 ; len < n+1 ; len++){
            for (int i = 1 ; i <= n-len+1 ; i++) {
                j = i + len-1;
                for (int k = i ; k < j ; k++) {
                    temp = ans[i][k] + ans[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    if (temp < ans[i][j] || ans[i][j] == 0){
                        ans[i][j] = ans[i][k] + ans[k+1][j] + arr[i-1]*arr[k]*arr[j] ;
                    }
                }
            }
        }
        // for (int i = 0 ; i < n+1 ; i++){
        //     for (int j = 0 ; j < n+1 ; j++){
        //         cout << ans[i][j] << " " ;
        //     }
        //     cout << endl;
        // }
        return ans[1][n];
    }
};