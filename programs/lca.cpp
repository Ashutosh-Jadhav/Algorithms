// initial approach

class Solution {
public:
    void ancestor(TreeNode* root, TreeNode* p, TreeNode* q,vector<TreeNode*>& arr,int &a,TreeNode* &f,int &flag){
        if (root == NULL) return;
        if (flag == 1) return;
        arr.push_back(root);
        if (f == NULL && root -> val == p->val) {a = arr.size()-1;f = p;}
        if (f == NULL && root -> val == q->val) {a = arr.size()-1;f = q;}
        ancestor(root->left,p,q,arr,a,f,flag);
        ancestor(root->right,p,q,arr,a,f,flag);
        if (f!= NULL && f == p && root->val == q->val) {flag = 1;return;}
        if (f!= NULL && f == q && root->val == p->val) {flag = 1;return; }
        if (flag == 1) return;
        arr.pop_back(); if (a > arr.size()-1) {a--;}
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val == q->val) return p;
        vector<TreeNode*> arr; 
        int flag = 0;
        int a = 0;                      // will point to ancestor
        TreeNode* f = NULL;
        ancestor(root,p,q,arr,a,f,flag);
        return arr[a];
    }
};