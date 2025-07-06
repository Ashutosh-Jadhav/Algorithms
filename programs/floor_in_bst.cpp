class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        while (root != NULL) {
            if (root->data == x) return x;
            if (x < root->data) root = root->left;
            else {
                if (ans < root->data) ans = root->data;
                root = root->right;
            }
        }
        return ans;
    }
};