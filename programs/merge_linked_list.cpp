#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node{
    int data = 10;
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

struct node * merge_ll(struct node * h1, struct node * h2) {
    struct node *h3,*temp,*p,*prev; h3 = new node(); temp = h3; prev = h3;

    while(h1 && h2) {
        if (h1->data < h2->data) {
            p = h1; h1 = h1->next;
        }
        else {
            p = h2 ; h2 = h2->next;
        }
        p -> next = NULL;
        prev -> next = p;
        prev = p;
    }
    while (h1) {
        p = h1;
        h1 = h1->next;
        p->next = NULL;
        prev -> next = p;
        prev = p;
    }
    while(h2) {
        p = h2;
        h2 = h2->next;
        p->next = NULL;
        prev -> next = p;
        prev = p;
    }

    h3 = h3 -> next;
    delete temp;
    return h3;
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
    head = head->next; delete tail;
    struct node *head2 = new node();
    head2 -> data = 30; prev = head2; head2->next = NULL; tail = head2;
    for (int i = 4 ; i < 60 ; i *= 3) {
        p = new node();
        p -> data = i; p->next = NULL;
        prev -> next = p;
        prev = p;
    }
    head2 = head2->next; delete tail;
    print_ll(head); print_ll(head2);
    node * h3 = merge_ll(head,head2);
    print_ll(h3);
    return 0;
}