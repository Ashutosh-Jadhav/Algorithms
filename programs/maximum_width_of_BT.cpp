class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        unsigned long long l,r,num;
        int s,max=1;
        TreeNode* u;
        q.push({root,1});
        while(!q.empty()) {
            s = q.size();
            for(int i = 0 ; i < s ; i++) {
                u = q.front().first; num = q.front().second; q.pop();
                if (i == 0) l = num;
                if (i == s-1) r = num;
                if (max < r-l+1 && l < r) max = r-l+1 ;
                if (u->left) q.push({u->left,2*num});
                if (u->right) q.push({u->right,2*num+1});
            }
        }
        return max;
    }
};