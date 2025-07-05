// O(log(n)^2)

class Solution {
public:
    bool exist(int mid,TreeNode* root,int h) {
        if (root == NULL) return false;
        if (h == 0) return true;
        if (mid > pow(2,h-1)) return exist(mid-pow(2,h-1),root->right,h-1);
        else return exist(mid,root->left,h-1);
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int l,r,mid,h = 0;
        TreeNode* curr=root;
        while (curr->left) {h++; curr = curr->left;}
        l = 1 ; r = pow(2,h);
        while(l <= r) {
            mid = (l+r)/2;
            if(exist(mid,root,h))l = mid+1;
            else r = mid-1;
        }
        return pow(2,h)+r-1;
    }
};