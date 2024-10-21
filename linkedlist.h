#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
    int data;
    struct node* next;
};

struct node* BuildOneTwoThree();
struct node* insertInit(struct node* head, int num);
struct node* insertFinal(struct node* head, int num);
struct node* insertAtPosition(struct node* head, int num, int position);
void printList(struct node* head);

#endif
