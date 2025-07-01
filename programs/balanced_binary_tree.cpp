// first approach

class Solution {
public:
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1+ max(depth(root->right),depth(root->left));
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;
        return abs(depth(root->left) - depth(root->right)) < 2;
    }
};

// optimized

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int left_h = height(root->left);
        int right_h = height(root->right);
        if (left_h == -1 || right_h == -1) return -1;
        if (abs(left_h - right_h) > 1) return -1;
        return 1+max(left_h,right_h);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1 ;
    }
};