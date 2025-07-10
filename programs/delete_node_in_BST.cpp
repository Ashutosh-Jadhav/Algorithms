class Solution {
public:
    TreeNode* search(TreeNode* root,int key,TreeNode*& p) {
        if (root == NULL) return NULL;
        if (root->val == key) return root;
        if (key < root->val) {p = root ;return search(root->left,key,p);}
        p = root;return search(root->right,key,p);
    }
    TreeNode* predecessor(TreeNode* root,TreeNode* &p) {
        if (root->left == NULL) return NULL;
        p = root;root = root->left;
        while(root->right) {p = root;root=root->right;}
        return root;
    }
    TreeNode* succesor(TreeNode* root,TreeNode* &p) {
        p = root;root = root->right;
        if (root == NULL) return NULL;
        while(root->left) {p = root;root=root->left;}
        return root;
    }
    void del(TreeNode* root,int key,TreeNode* p) {
        if (root == NULL) return ;
        if (!root->right && !root->left) {
            if (p->right && p->right->val == key) p->right=NULL;
            else if(p->left && p->left->val==key) p->left=NULL;
            delete root;root=nullptr; return ;
        }
        TreeNode* pred;
        pred = predecessor(root,p); 
        if (pred == NULL) pred = succesor(root,p);
        root->val = pred->val;
        pred->val = key;
        del(pred,key,p);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        TreeNode* node; 
        TreeNode* p = root;
        node = search(root,key,p);
        if (node == root && !node->right && !node->left) {delete root;return nullptr;}
        del(node,key,p);
        return root;
    }
};