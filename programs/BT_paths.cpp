// initial approach

class Solution {
public:
    void paths(TreeNode* root , vector<int>& arr , vector<string>& ans) {
        if (root == NULL) return ;
        string s = "";
        char c;
        arr.push_back(root->val);
        if (root -> left == NULL && root-> right == NULL) {
            for (int i = 0 ; i < arr.size() ;i++) {
                s = s+to_string(arr[i]);
                if (i < arr.size()-1)s = s+"->";
            }
            ans.push_back(s);
        }
        paths(root->left,arr,ans);
        paths(root->right,arr,ans);
        arr.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> arr;
        vector<string> ans;
        paths(root,arr,ans);
        return ans;
    }
};