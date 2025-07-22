class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows,col,l,r,max = 0; rows = matrix.size(); col = matrix[0].size();
        vector<int> n_s_r(col,-1),n_s_l(col,-1);
        stack<int>s1; stack<int> s2;
        vector<vector<int>> counts(rows,vector<int>(col,0));
        for (int i = 0 ; i < rows ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (i==0) {counts[i][j] = matrix[i][j]-'0';}
                else if(matrix[i][j] == 0+'0') counts[i][j]=0;
                else counts[i][j] = 1+counts[i-1][j];
            }
        }
        for (int i = 0 ; i < rows ; i++) {
            for (int j = 0 ; j < col ; j++) {
                // counts[i] is vector for which we will find next smallest
                while (!s1.empty() && counts[i][j] < counts[i][s1.top()]) {n_s_r[s1.top()] = j;s1.pop();}
                while (!s2.empty() && counts[i][col-j-1] < counts[i][s2.top()]) {n_s_l[s2.top()] = col-j-1;s2.pop();}
                s1.push(j); s2.push(col-j-1);
            }
            while(!s1.empty()) s1.pop(); while(!s2.empty()) s2.pop();
            for (int k = 0 ; k < col ; k++) {
                l = -1; r = col;
                if(n_s_l[k] != -1) l = n_s_l[k]; if(n_s_r[k] != -1) r = n_s_r[k];
                if (max < (r-l-1)*counts[i][k]) max = counts[i][k]*(r-l-1);
            }
            n_s_l.assign(col,-1); n_s_r.assign(col,-1);
        }
        return max;
    }
};