//
//  sLList.h
//  LList
//
//  Created by Anu on 4/1/15.
//

#ifndef __sLList__LList__
#define __sLList__LList__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct list{
    int x;
    struct list *next;
}llist;

void print_list(llist * head);
int push_first(llist **head, int data);
int push_last(llist **head, int data);
int push_value(llist **head, int value, int data);
int push_index(llist **head, int index, int data);
int pop_first(llist **head);
int pop_last(llist **head);
int pop_value(llist **head, int value);
int pop_index(llist **head, int index);

#endif /* defined(__LList__LList__) */
