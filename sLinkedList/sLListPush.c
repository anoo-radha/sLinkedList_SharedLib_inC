//
//  LListPush.c
//  LList
//
//  Created by Anu on 4/1/15.
//
//  Singly linked list to push values based on index or value

#include "/usr/include/sLList.h"


//add to the beginning of llist
int push_first(llist **head, int data)
{
    llist *current;
    current = (llist*)malloc(sizeof(llist));
    if (current == NULL) return 1;
    current->x = data;
    current->next = *head;
    *head = current;
    return 0;
}

//add to last node
int push_last(llist **head, int data)
{
    //if linked list is empty
    if (*head == NULL) {
#ifdef DEBUG
        printf("Adding first node..\n");
#endif
        push_first(head, data);
        return 0;
    }
    llist *current = *head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = (llist*)malloc(sizeof(llist));
    if (current == NULL) return 1;
    current->next->x = data;
    current->next->next = NULL;
    return 0;
    
}

//pushing/adding x next to the node with the passed value
int push_value(llist **head, int value, int data)
{
    //if linked list is empty
    if (*head == NULL) {
        printf("List is empty\n\n");
        return -1;
    }
    //if linked list has only one node
    if ((*head)->next == NULL)
    {
        if ((*head)->x == value)
        {
            return push_last(head, data);
        }
        else
        {
            printf("Node with value %d not found\n", value);
            return -1;
        }
        
    }
    llist *current = *head;
    while(current->next != NULL)
    {
        if(current->x == value){
            if(current->next == NULL)
            {
                return push_last(head, data);
            }
            else
            {
                llist* node;
                node = (llist*)malloc(sizeof(llist));
                if (node == NULL) return 1;
                node->x = data;
                node->next=current->next;
                current->next = node;
                return 0;
            }
        }
        current = current->next;
    }
    //if last node has the matching value
    if(current->x == value)
    {
        return push_last(head, data);
    }
    printf("Node with value %d not found\n", value);
    return -1;
}

//pushing/adding x next to the node with the passed index
int push_index(llist **head, int index, int data)
{
    int x = 0;
    if(index<=0)
        printf("Valid index plz..\n");
    //if index is 1
    if(index == 1)
    {
#ifdef DEBUG
        printf("Adding first node..\n");
#endif
        return push_first(head, data);
        
    }
    //if linked list is empty
    if (*head == NULL)
    {
        printf("List is empty\n\n");
        return -1;
    }
    //if linked list has only one node
    if ((*head)->next == NULL)
    {
        switch(index)
        {
            case 2:
                return push_last(head, data);
            default:
                printf("Node with index %d not found\n\n", index);
                return -1;
        }
        
    }
    llist *current = (*head), *temp = NULL, *node;
    for(x = 1;x<=index;x++)
    {
        if(x == index)
        {
            node = (llist*)malloc(sizeof(llist));
            if (node == NULL) return 1;
            node->x = data;
            node->next=current;
            temp->next = node;
            return 0;
        }
        temp = current;
        if(current->next != NULL)
            current = current->next;
        else
        {
            if(index == x+1)
            {
                return push_last(head, data);
            }
            printf("Node with index %d not found\n\n", index);
            return -1;
        }
    }
    return 0;
}

//printing the singly linked list
void print_list(llist *head)
{
    int i = 1;
    llist *current = head;
    
    while(current !=NULL){
#ifdef DEBUG
        printf("Node %d has a value %d\n", i,current->x);
#else
        printf("| %d |-->", current->x);
#endif
        current = current->next;
        i++;
    }
    printf("EndofList\n\n");
}