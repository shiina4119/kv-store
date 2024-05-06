#include "db.h"
#include "linkedlist.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    node *head = create_new_node();
    FILE *fp = fopen("database.txt", "r");
    read_db(head, fp);

    for (int i = 1; i < argc; ++i) {
        char *op = NULL;
        op = strsep(&argv[i], ",");
        if (strlen(op) > 1) {
            fprintf(stderr, "bad command\n");
            continue;
        }
        switch (op[0]) {
        case 'p': {
            int key = atoi(strsep(&argv[i], ","));
            char *value = argv[i];
            bool found = false;
            node *p = head->next;
            node *new = NULL;
            while (p) {
                if (p->key == key) {
                    p->value = value;
                    found = true;
                    break;
                }
                if (p->next) {
                    p = p->next;
                } else {
                    break;
                }
            }
            if (!found) {
                new = create_new_node();
                new->key = key;
                new->value = value;
                if (!p) {
                    head->next = new;
                } else {
                    p->next = new;
                }
            }
            break;
        }
        case 'g': {
            int key = atoi(strsep(&argv[i], ","));
            node *p = head->next;
            while (p) {
                if (key == p->key) {
                    print_node(p);
                    break;
                }
                p = p->next;
            }
            if (!p) {
                printf("%d not found\n", key);
            }
            break;
        }
        case 'd': {
            int key = atoi(strsep(&argv[i], ","));
            node *p = head;
            while (p->next) {
                if (p->next->key == key) {
                    p->next = p->next->next;
                    break;
                }
                p = p->next;
            }
            break;
        }
        case 'c':
            head->next = NULL;
            break;
        case 'a': {
            node *p = head->next;
            while (p) {
                print_node(p);
                p = p->next;
            }
            break;
        }
        default:
            fprintf(stderr, "bad command\n");
        }
    }

    fclose(fp);
    fp = fopen("database.txt", "w");
    write_db(head, fp);
    fclose(fp);
    free(head);
    return 0;
}
