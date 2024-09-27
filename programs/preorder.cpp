#include <iostream>
using namespace std ;

struct Node {
    int data ;
    struct Node* left, *right ;
    Node(int data)
    {
        this -> data = data ;
        left = right = NULL ;
    }
};

void preorder(struct Node *node)
{
    if (node == NULL)
    return;
    cout << node->data << " " ;
    preorder(node -> left);
    preorder(node -> right);
}

int main()
{
    struct Node* root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(100);
    root -> left -> right = new Node(200);
    root -> right -> left = new Node(35);
    preorder(root);
    cout << endl;
}
