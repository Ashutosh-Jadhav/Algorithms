class Solution {
public:
    void search(TreeNode* root, TreeNode* p,vector<TreeNode*>& path) {
        if (root == NULL) return;
        path.push_back(root);
        if (root->val == p->val) return;
        if (p->val > root->val) search(root->right,p,path);
        else search(root->left,p,path);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p,path_q;
        int i;
        search(root,p,path_p); search(root,q,path_q);
        i = min(path_p.size(),path_q.size());i--;
        while (path_p[i] != path_q[i]) i--;
        return path_p[i];
    }
};

// optimized

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while((p->val > root->val && q->val > root->val) || (p->val < root->val && q->val < root->val)) {
            if (p->val > root->val) root = root->right;
            else root = root->left;
        }
        return root;
    }
};