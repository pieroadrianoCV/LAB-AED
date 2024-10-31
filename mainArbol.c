#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int lookup(struct node* node, int target) {
    if (node == NULL)
        return false;
    
    printf("Valor recorrido: %d\n", node->data);

    if (target == node->data)
        return true;
    if (target < node->data)
        return lookup(node->left, target);
    else
        return lookup(node->right, target);
}

struct node* newNode(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL)
        return newNode(data);
    if (data <= node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int target = 200;
    if (lookup(root, target))
        printf("El valor %d se encuentra en el árbol.\n", target);
    else
        printf("El valor %d no se encuentra en el árbol.\n", target);

    return 0;
}
