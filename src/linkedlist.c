#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

node *create_new_node() {
    node *new = malloc(sizeof(node));
    new->key = 0;
    new->value = NULL;
    new->next = NULL;
    return new;
}

void free_list(node *head) {
    node *curr = head;
    while (curr) {
        node *next = curr->next;
        free(curr);
        curr = next;
    }
}

void print_node(node *n) {
    printf("%d,%s\n", n->key, n->value);
}
