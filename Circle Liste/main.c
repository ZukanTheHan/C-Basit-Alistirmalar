#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *insert_beg(struct node *start, int num)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    if(start !=NULL)
    {
        ptr=start;
        while(ptr -> next != start)
            ptr=ptr->next;
        ptr -> next = new_node;
        new_node -> next = start;
    }
    else
    {
        new_node -> next = new_node;

    }
    start = new_node;
    return start;



};
struct node *insert_end(struct node *start,,int num)
{
    struct node *ptr, *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while (ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> next = start;
    return start;
};
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    if(ptr -> next == start)
            return NULL;
    while(ptr -> next != start)
        ptr=ptr->next;
    ptr->next=start->next;
    free(start);
    start = ptr->next;
    return start;
};
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr=start;
    if(ptr->next==start)
        return NULL;
    while(ptr -> next != start )
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;

};
void *display(struct node *start)
{
    struct node *ptr;
    if(start != NULL)
    {
        ptr=start;
        while(ptr->next != start)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\t",ptr->data);
        printf("\n");
    }
}





int main()
{

    return 0;
}
