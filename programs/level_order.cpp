class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*>q ;
        q.push(root);
        int s;
        TreeNode* u = NULL;
        while(!q.empty()) {
            s = q.size(); level.clear();
            for (int i = 0 ; i < s ; i++) {
                u = q.front(); q.pop();
                if (u == NULL) continue;
                level.push_back(u->val);
                q.push(u->left);
                q.push(u->right);
            }
            if (!level.empty()) ans.push_back(level);
        }
        // for (int i = 0 ; i < level.size() ; i++) cout << level[i] << " ";
        return ans;
    }
};