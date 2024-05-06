#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_db(node *head, FILE *fp) {
    node *p = head;
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        node *new = create_new_node();
        new->key = atoi(strsep(&line, ","));
        new->value = strsep(&line, ",");
        new->value[strcspn(new->value, "\n")] = '\0';
        p->next = new;
        p = p->next;
    }
}

void write_db(node *head, FILE *fp) {
    node *p = head->next;
    while (p) {
        fprintf(fp, "%d,%s\n", p->key, p->value);
        p = p->next;
    }
}
