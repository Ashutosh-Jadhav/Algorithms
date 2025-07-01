class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> lev;
        queue<TreeNode*> q;
        TreeNode* u; int s;int c = 0;
        if (root)q.push(root);
        while(!q.empty()) {
            s = q.size();
            for (int i = 0 ; i < s ; i++) {
                u = q.front(); q.pop();
                lev.push_back(u->val);
                if (u->left != NULL) q.push(u->left);
                if (u->right != NULL) q.push(u->right);
            }
            if (c++ % 2 == 1) reverse(lev.begin(),lev.end());
            ans.push_back(lev);
            lev.clear();
        }
        return ans;
    }
};