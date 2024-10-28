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
struct node* orderList(struct node* head);
struct node* deleteNode(struct node* head, int num);
struct node* deleteInitNode(struct node* head);
struct node* deleteFinalNode(struct node* head);
struct node* searchNode(struct node* head, int num);

#endif
