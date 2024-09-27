#include <iostream>
#include <math.h>
using namespace std ;

struct Node {
    int data ;
    struct Node *left, *right ;
    Node(int data)
    {
        this->data = data ;
        left = right = NULL ;
    }
};

void printInorder(struct Node* node)
{
    if(node == NULL)
    return;
    printInorder(node->left);
    cout << node -> data << " ";
    printInorder(node -> right);
}

int main()
{
    struct Node *root =  new Node(1) ;
    root -> left = new Node(2);
    root ->right = new Node(3);
    root -> left -> left = new Node(4);
    root -> right -> left = new Node(5);
    cout << "Inorder traversal of binary tree is  \n";
    printInorder(root);
    cout << "\n";
    // cout << root->data << endl;
    // cout << root->left << endl;
    // cout << root->right << endl;
    return 0 ;
}