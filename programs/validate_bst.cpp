class Solution {
public:
    bool is_bst(TreeNode* root ,long long &last) {
        if (root == NULL) return true;
        if(!is_bst(root->left,last)) return false;
        if (last >= root->val) return false;
        last = root->val;
        if(!is_bst(root->right,last)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long last = (-1)*pow(2,32);
        return is_bst(root,last);
    }
};


// another approach

class Solution {
public:
    bool is_bst(TreeNode* root ,long long min_val, long long max_val) {
        if (root == NULL) return true;
        if (root->val <= min_val || root->val >= max_val) return false;
        return (is_bst(root->right,root->val,max_val) && is_bst(root->left,min_val,root->val));
    }
    bool isValidBST(TreeNode* root) {
        return is_bst(root,LLONG_MIN,LLONG_MAX);
    }
};