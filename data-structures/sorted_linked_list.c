#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define LIST_LENGTH 12

int main(void){
    int L[LIST_LENGTH] = {2, 4, 6, 1, 3, 5, 6, 5, 4, 3, 2, 1};
    node *head = NULL;
    for (int i = 0; i < LIST_LENGTH; i++){
        node *temp = malloc(sizeof(node));
        if (temp == NULL){
            free_list(head);
            return 1;
        }
        temp->number = L[i];
        temp->next = NULL;
        if (head == NULL){
            head = temp;
        } else if (temp->number <= head->number){
            temp->next = head;
            head = temp;
        } else {
            node *ptr = head;
            while (ptr->next != NULL && temp->number > ptr->next->number){
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    print_list(head);
    free_list(head);
    return 0;
}
