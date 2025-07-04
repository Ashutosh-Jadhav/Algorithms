class Solution {
public:
    void pre(TreeNode* root, unordered_map<int,TreeNode*>& um,TreeNode* p) {
        if (root == NULL) return;
        um.insert({root->val,p});
        pre(root->left,um,root);
        pre(root->right,um,root);
    }
    vector<int> bfs(TreeNode* s,unordered_map<int,TreeNode*> um,int k) {
        queue<TreeNode*> q;
        vector<int> ans;
        unordered_map<int,int> vis;
        TreeNode* p;
        TreeNode* u = NULL;
        int v,c=0,size;
        q.push(s); vis.insert({s->val,1});
        while(!q.empty()) {
            size = q.size();
            for (int i = 0 ; i < size ; i++) {
                u = q.front(); v = u->val; q.pop();
                p = um[v];
                if (u != p && vis.find(p->val) == vis.end()) {q.push(p); vis.insert({p->val,1});}
                if (u->right && vis.find(u->right->val) == vis.end()) {q.push(u->right); vis.insert({u->right->val,1});}
                if (u->left && vis.find(u->left->val) == vis.end()) {q.push(u->left); vis.insert({u->left->val,1});}
                if (c == k) ans.push_back(u->val);
            }
            if (c == k) return ans;
            c++;
        }
        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) return {target->val};
        unordered_map<int,TreeNode*> um;
        pre(root,um,root);
        return bfs(target,um,k);
    }
};