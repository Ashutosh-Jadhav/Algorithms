class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n,m,mi=0,max = 0; n = matrix.size(); m = matrix[0].size();
        vector<vector<int>> ans(n+1,vector<int>(m+1,0));
        for (int i = n-1 ; i >= 0  ; i--) {
            for (int j = m-1 ; j >= 0 ; j--) {
                if (matrix[i][j] == '0') ans[i][j]=0;
                else {
                    mi = min(ans[i+1][j],ans[i][j+1]);
                    ans[i][j] = 1+min(mi,ans[i+1][j+1]);
                    if (max < ans[i][j]) max = ans[i][j];
                }
            }
        }
        return max*max;
    }
};