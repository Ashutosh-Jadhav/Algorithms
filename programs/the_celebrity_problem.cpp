class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int c,n; c = 0 ; n = mat.size();
        for (int i = 0 ; i < n ; i++) {
            if (!mat[i][c]) c = i;
        }
        for (int i = 0 ; i < n ; i++) {
            if (i == c) continue;
            if (mat[c][i] || !mat[i][c]) return -1;
        }
        return c;
    }
};