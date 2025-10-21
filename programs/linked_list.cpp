#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next = NULL;
};

// struct linked_list{
//     struct node *head;
// };
void print_ll(struct node* head) {
    while(head) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

int main() {
    struct node *head = new node();
    struct node *tail; tail = head;
    struct node *p, *prev;
    head->data = 10; head->next = NULL; prev = head;
    for (int i = 1 ; i < 30 ; i *= 3) {
        p = new node();
        p -> data = i; p->next = NULL;
        prev -> next = p;
        prev = p;
    }
    struct node *head2 = new node();
    head2 -> data = 30; prev = head2; head2->next = NULL;
    for (int i = 2 ; i < 30 ; i *= 3) {
        p = new node();
        p -> data = i; p->next = NULL;
        prev -> next = p;
        prev = p;
    }
    print_ll(head); print_ll(head2);
    return 0;
}