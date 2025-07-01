#include <iostream>
using namespace std ;

struct Node {
    int data;
    struct Node * left , *right ;
    Node(int data)
    {
        this -> data = data ;
        left = right = NULL ;
    }

};

void postorder(struct Node *node)
{
    if (node == NULL)
    return;
    postorder(node -> left);
    postorder(node -> right);
    cout << node -> data << " ";
}

int main()
{
    struct Node * root ;
    root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> right -> left = new Node(5);
    postorder(root);
    cout << endl ;
}

// iterative (2 stack)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s1; stack<TreeNode*> s2;
        TreeNode* curr;
        s1.push(root);
        while(!s1.empty()) {
            curr = s1.top(); s1.pop();
            if (curr == NULL) continue;
            s2.push(curr);
            s1.push(curr->left);
            s1.push(curr->right);
        }
        while(!s2.empty()) {
            ans.push_back(s2.top()->val); s2.pop();
        }
        return ans;
    }
};


// 1 stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* curr = NULL; TreeNode* prev = NULL; TreeNode* node = NULL;
        curr = root;
        while(!s.empty() || curr != NULL) {
            if (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                node = s.top();
                if (node -> right != NULL && node->right!= prev) {
                    curr = node->right;
                }
                else {
                    ans.push_back(node->val);
                    prev = node;
                    s.pop();
                }
            }
        }
        return ans;
    }
};


// all traversals using 1 stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre; vector<int> post; vector<int> in;
        stack<pair<TreeNode*,int>> s;
        pair<TreeNode*,int> curr;
        s.push({root,1});
        while(!s.empty() && root != NULL) {
            curr = s.top();
            if (curr.second == 1) {
                pre.push_back(curr.first->val);
                s.top().second++;
                if (curr.first->left != NULL) {
                    s.push({curr.first->left,1});
                }
            }
            else if (curr.second == 2) {
                in.push_back(curr.first->val);
                s.top().second++;
                if (curr.first->right != NULL) {
                    s.push({curr.first->right,1});
                }
            }
            else {
                post.push_back(curr.first->val);
                s.pop();
            }
        }
        return post;
    }
};