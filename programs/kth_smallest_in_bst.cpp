class Solution {
public:
    int in_order(TreeNode* root,int& k,int &ans) {
        if(root->left) in_order(root->left,k,ans);
        k--;
        if (k == 0) ans = root->val;
        if(root->right)in_order(root->right,k,ans);
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        in_order(root,k,ans);
        return ans;
    }
};
