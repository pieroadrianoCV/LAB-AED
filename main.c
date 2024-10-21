#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

struct node* insertInit(struct node* head, int num) {
    struct node* new = malloc(sizeof(struct node));
    new->data = num;
    new->next = head;
    return new;
}

struct node* insertFinal(struct node* head, int num) {
    struct node* new = malloc(sizeof(struct node));
    struct node* current = head;

    new->data = num;
    new->next = NULL;

    if (head == NULL) {
        return new;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new;
    return head;
}

struct node* insertAtPosition(struct node* head, int num, int position) {
    struct node* new = malloc(sizeof(struct node));
    struct node* current = head;
    new->data = num;

    if (position == 0) {
        new->next = head;
        return new;
    }

    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("La posición es mayor que la longitud de la lista.\n");
        return head;
    }

    new->next = current->next;
    current->next = new;
    
    return head;
}

void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = BuildOneTwoThree();
    head = insertInit(head, 0);
    head = insertFinal(head, 5);
    head = insertAtPosition(head, 4, 3);

    printList(head);

    return 0;
}
