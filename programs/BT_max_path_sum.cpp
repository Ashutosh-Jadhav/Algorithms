class Solution {
public:
    int post(TreeNode* root, int &max) {
        if (root == NULL) return -1001;
        int ans,left,right;
        left = post(root->left,max); 
        right = post(root->right,max);
        if (left+right+root->val > max) max = left+right+root->val;
        left+root->val > right+root->val ? ans = left+root->val : ans = right+root->val;
        if (root->val > ans) ans = root->val;
        if (ans > max) max = ans;
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        int max = -1001 ;
        post(root,max);
        return max;
    }
};