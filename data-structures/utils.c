#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void free_list(node *head){
    while (head != NULL){
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

void print_list(node *head){
    node *ptr = head;
    while (ptr != NULL){
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}