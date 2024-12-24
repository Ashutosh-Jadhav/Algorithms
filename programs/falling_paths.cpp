class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int min = 10100;
        vector<vector<int>> ans(n,vector<int>(n,0));
        for (int j =0 ; j < n ; j++){
            ans[0][j] = matrix[0][j];
        }
        for (int i =1 ; i < n ; i++){
            for (int j =0 ; j < n ; j++){
                if (j == 0 ){
                    if (ans[i-1][j] < ans[i-1][j+1]){
                        ans[i][j] = matrix[i][j] + ans[i-1][j];
                    }
                    else{
                        ans[i][j] = matrix[i][j] + ans[i-1][j+1];
                    }
                }
                else if (j == n-1){
                    if (ans[i-1][j-1] < ans[i-1][j]){
                        ans[i][j] = matrix[i][j] + ans[i-1][j-1];
                    }
                    else {
                        ans[i][j] = matrix[i][j] + ans[i-1][j];
                    }
                }
                else {
                    if (ans[i-1][j-1] < ans[i-1][j] && ans[i-1][j-1] < ans[i-1][j+1]){
                        ans[i][j] = matrix[i][j] + ans[i-1][j-1];
                    }
                    else if (ans[i-1][j] < ans[i-1][j+1]){
                        ans[i][j] = matrix[i][j] + ans[i-1][j];
                    }
                    else{
                        ans[i][j] = matrix[i][j] + ans[i-1][j+1];
                    }
                }
            }
        }
        for (int j = 0 ; j < n ; j++){
            if (ans[n-1][j] < min){
                min  = ans[n-1][j];
            }
        }
        return min ;
    }
};


// Space Optimized 

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int min = 10100;
        vector<vector<int>> ans(2,vector<int>(n,0));
        for (int j =0 ; j < n ; j++){
            ans[0][j] = matrix[0][j];
        }
        for (int i =1 ; i < n ; i++){
            for (int j =0 ; j < n ; j++){
                if (j == 0 ){
                    if (ans[(i-1)%2][j] < ans[(i-1)%2][j+1]){
                        ans[i%2][j] = matrix[i][j] + ans[(i-1)%2][j];
                    }
                    else{
                        ans[i%2][j] = matrix[i][j] + ans[(i-1)%2][j+1];
                    }
                }
                else if (j == n-1){
                    if (ans[(i-1)%2][j-1] < ans[(i-1)%2][j]){
                        ans[i%2][j] = matrix[i][j] + ans[(i-1)%2][j-1];
                    }
                    else {
                        ans[i%2][j] = matrix[i][j] + ans[(i-1)%2][j];
                    }
                }
                else {
                    if (ans[(i-1)%2][j-1] < ans[(i-1)%2][j] && ans[(i-1)%2][j-1] < ans[(i-1)%2][j+1]){
                        ans[i%2][j] = matrix[i][j] + ans[(i-1)%2][j-1];
                    }
                    else if (ans[(i-1)%2][j] < ans[(i-1)%2][j+1]){
                        ans[i%2][j] = matrix[i][j] + ans[(i-1)%2][j];
                    }
                    else{
                        ans[i%2][j] = matrix[i][j] + ans[(i-1)%2][j+1];
                    }
                }
            }
        }
        for (int j = 0 ; j < n ; j++){
            if (ans[(n-1)%2][j] < min){
                min  = ans[(n-1)%2][j];
            }
        }
        return min ;
    }
};