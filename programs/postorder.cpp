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