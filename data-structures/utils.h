#ifndef UTILS_H
#define UTILS_H

typedef struct node {
    int number;
    struct node *next;
} node;

void free_list(node *head);

void print_list(node *head);

#endif