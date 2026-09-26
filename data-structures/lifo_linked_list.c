#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main(void){
    node *head = NULL;
    for (int i = 0; i < 3; i++){
        node *temp = malloc(sizeof(node));
        if (temp == NULL){
            free_list(head);
            return 1;
        }
        temp->number = i + 1;
        temp->next = head;
        head = temp;
    }
    print_list(head);
    free_list(head);
    return 0;
}
