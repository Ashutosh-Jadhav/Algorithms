class Solution {
public:
    void inorder(TreeNode* root,vector<int>& ans) {
        if (root == NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};



// iterative

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        stack<TreeNode*> s;
        while (curr != nullptr || !s.empty()) {
            while(curr != nullptr) {
                s.push(curr);
                curr = curr-> left;
            }
            curr = s.top(); s.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};