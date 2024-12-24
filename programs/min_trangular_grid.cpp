class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        int min = 10001;
        vector<vector<int>> ans(2, vector<int>(n, 10000+1));
        ans[0][0] = triangle[0][0];
        for (int i = 1 ; i < m  ; i++){
            for (int j = 0 ; j < i+1 ; j++){
                if(j<1 || ans[(i-1)%2][j] < ans[(i-1)%2][j-1]){
                    ans[i%2][j] = triangle[i][j] + ans[(i-1)%2][j];
                }
                else{
                    ans[i%2][j] = triangle[i][j] + ans[(i-1)%2][j-1];
                }
            }
        }
        for (int k = 0 ; k < n ; k++)
        {
            if (ans[(n-1)%2][k] < min){
                min = ans[(n-1)%2][k];
            }
        }
        return min ;
    }
};