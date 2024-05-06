#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int i = 0;
    char *op = NULL;
    for (i = 1; i < argc; ++i) {
        op = strsep(&argv[i], ",");
        if (strlen(op) > 1) {
            fprintf(stderr, "bad command\n");
            continue;
        }
        switch (op[0]) {
        case 'p': {
            printf("put command\n");
            break;
        }
        case 'g': {
            printf("get command\n");
            break;
        }
        case 'd': {
            printf("delete command\n");
            break;
        }
        case 'c':
            printf("clear command\n");
            break;
        case 'a': {
            printf("show all command\n");
            break;
        }
        default:
            fprintf(stderr, "bad command\n");
        }
    }
    return 0;
}
