class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        if (root == NULL) {root = new TreeNode(val);return root;}
        while(temp != NULL) {
            if (val > temp->val) {
                if (temp->right == NULL) {temp->right = new TreeNode(val);break;}
                temp=temp->right;
            }
            else {
                if (temp->left == NULL) {temp->left = new TreeNode(val);break;}
                temp = temp->left;
            }
        }
        return root;
    }
};