//
//  Llist.c
//  LList
//
//  Created by Anu on 6/18/15.
//

#include <stdio.h>
#include "/usr/include/sLList.h"

int main(int argc, const char * argv[]) {
    
    int i = 0;

    printf("Hello, Linked List!\n");
    llist *head = NULL;
    
    //Creating linkedlist
    push_last(&head, 5);
    push_first(&head, 1);
    push_value(&head, 1, 2);
    push_index(&head, 1, 12);
    print_list(head);
    
    //Popping Now!
    i = pop_first(&head);
    printf("value of node popped is  %d\n\n", i);
    i = pop_last(&head);
    printf("value of node popped is %d\n\n", i);
    print_list(head);
    
    //Pushing some more
    push_first(&head, 11);
    push_value(&head, 1, 22);
    print_list(head);
    
    //Popping again
    i = pop_value(&head, 11);
    printf("value of node popped is %d\n\n", i);
    i = pop_index(&head, 2);
    printf("value of node popped is %d\n\n", i);
    print_list(head);
    
    return 0;
}
