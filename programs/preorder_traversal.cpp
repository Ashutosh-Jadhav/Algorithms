class Solution {
public:
    void preorder(TreeNode* root,vector<int>& ans) {
        if (root == NULL) return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};

// iterative

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* u;
        s.push(root);
        while(!s.empty()) {
            u = s.top(); s.pop();
            if (u == NULL) continue;
            s.push(u->right) ;
            s.push(u->left);
            ans.push_back(u->val);
        }
        return ans;
    }
};