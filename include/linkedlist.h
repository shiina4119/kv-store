#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node;

typedef struct node {
    int key;
    char *value;
    struct node *next;
} node;

node *create_new_node();

void free_list(node *);

void print_node(node *);

#endif
