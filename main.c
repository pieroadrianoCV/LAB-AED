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

struct node* orderList(struct node* head) {
    if (head == NULL) {
        return head;
    }
    
    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;              
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;

    } while (swapped);

    return head;
}


struct node* deleteNode(struct node* head, int num) {
    struct node* current = head;
    struct node* prev = NULL;

    if (current != NULL && current->data == num) {
        head = current->next;
        free(current);
        return head;
    }

    while (current != NULL && current->data != num) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("El valor %d no se encuentra en la lista.\n", num);
        return head;
    }

    prev->next = current->next;
    free(current);

    return head;
}

struct node* searchNode(struct node* head, int num) {
    struct node* current = head;

    while (current != NULL) {
        if (current->data == num) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}


int main() {
    struct node* head = BuildOneTwoThree();
    head = insertInit(head, 0);
    head = insertFinal(head, 5);
    head = insertAtPosition(head, 4, 3);
    head = orderList(head);
    head = deleteNode(head, 2);

    int valueToSearch = 2;
    struct node* foundNode = searchNode(head, valueToSearch);

    if (foundNode != NULL) {
        printf("Nodo con valor %d encontrado en la lista.\n", foundNode->data);
    } else {
        printf("Nodo con valor %d no encontrado en la lista.\n", valueToSearch);
    }

    printList(head);

    return 0;
}
