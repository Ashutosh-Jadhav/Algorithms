int findCeil(Node* root, int input) {
    // Your code here
    int ans=100001;
    while(root != NULL) {
        if (root->data == input) {ans = input;break;}
        else if (input > root->data) root = root->right;
        else {
            if (ans > root->data) ans = root->data;
            root = root->left;
        }
    }
    if (ans == 100001) return -1;
    return ans;
}