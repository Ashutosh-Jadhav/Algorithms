class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL) return q == NULL ;
        if (q == NULL) return p == NULL ;
        if (p->val != q->val) return false;
        if (!isSameTree(p->left,q->left)) return false;
        if (!isSameTree(p->right,q->right)) return false;
        return true;
    }
};