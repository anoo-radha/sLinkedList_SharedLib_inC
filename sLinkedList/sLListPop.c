//
//  LListPop.c
//  LList
//
//  Created by Anu on 4/2/15.
//
//Singly linked list to pop values based on index or value

#include "/usr/include/sLList.h"


//popping/removing first node
int pop_first(llist **head)
{
    //if linked list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    llist *current = NULL;
    int i = (*head)->x;
    current = (*head)->next;
    free(*head);
    *head = current;
    return i;
    
}

//popping/removing last node
int pop_last(llist **head)
{
    int i = 0;
    //if linked list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    // if there is only one item in the list, remove it
    if((*head)->next==NULL)
    {
        i = (*head)->x;
        free(*head);
        *head = NULL;
        return i;
    }
    llist *current = (*head);
    while(current->next->next != NULL)
    {
        current = current->next;
    }
    i = current->next->x;
    free(current->next);
    current->next = NULL;
    return i;
    
}

//popping/removing the node with the passed value
int pop_value(llist **head, int value)
{
    int i = 0;
    //if linked list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    //if its the first node
    if((*head)->x == value)
    {
        return pop_first(head);
    }
    
    llist *current = (*head);
    while(current->next != NULL)
    {
        if(current->next->x == value)
        {
            i = current->next->x;
            if(current->next->next == NULL)
            {
                free(current->next);
                current->next = NULL;
                return i;
            }
            else
            {
                free(current->next);
                current->next = current->next->next;
                return i;
            }
        }
        current = current->next;
    }
    //if last node has the matching value
    if(current->x == value)
    {
        return pop_last(head);
    }
    printf("Node with value %d not found\n", value);
    return -1;
    
}

//popping/removing the node with the passed index
int pop_index(llist **head, int index)
{
    int i = 0, x = 0;
    if(index<=0)
        printf("Valid index plz..\n");
    
    //if linked list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    if( ((*head)->next == NULL) && ( index>1))
    {
        printf("Just one node..cant pop a greater index!\n");
        return -1;
    }
    //if its the first node
    if(index == 1)
    {
        return pop_first(head);
    }
    
    llist *current = (*head);
    llist *temp = NULL;
    for(x = 1;x<=index;x++)
    {
        if(x == index)
        {
            i = current->x;
            if(current->next == NULL)
            {
                return pop_last(head);
            }
            else
            {
                temp->next = current->next;
                free(current);
                return i;
            }
            
        }
        temp = current;
        if(current->next != NULL)
        {
            current = current->next;
        }
        else{
            printf("Node with index %d not found\n", index);
            return -1;
        }
    }
    return i;
}

