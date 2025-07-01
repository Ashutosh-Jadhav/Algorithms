class Solution {
public:
    pair<int,int> dia(TreeNode* root) {
        if (root == NULL) return {0,0};
        pair<int,int> l_h = dia(root->left);
        pair<int,int> r_h = dia(root->right);
        int dia = max(l_h.second,r_h.second);
        if (l_h.first+r_h.first > dia) dia = l_h.first+r_h.first;
        int h = 1+ max(l_h.first,r_h.first);
        return {h,dia};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root).second;
    }
};