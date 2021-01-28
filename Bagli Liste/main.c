#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next
};

struct node *insert_beg(struct node *start,int num)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    new_node -> next = start;
    start = new_node;
    return start;

};
struct node *insert_end(struct node *start, int num)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    new_node -> next = NULL;
    ptr = start;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    ptr -> next = new_node;
    return start;
};
struct node *insert_after(struct node *start, int num, int val)
{
    struct node *new_node, *ptr, *preptr ;
    new_node -> data = num;
    preptr = start;
    ptr = start -> next;
    while(ptr != NULL && preptr -> data != val)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    if(ptr != NULL)
    {
        preptr -> next = new_node;
        new_node -> next = ptr;
    }
    return start;


};
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start -> next;
    free(ptr);
    return start;
};
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr-> next !=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr == start)
        return NULL;
    preptr -> next = NULL;
    free(ptr);
    return start;
};
struct node *delete_node(struct node *start,int pos)
{
    struct node *ptr, *preptr;
    ptr = start;
    if(ptr ->data == pos)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while(ptr != NULL && ptr -> data != pos)
        {
            preptr = ptr;
            ptr = ptr -> next;

        }
        if(ptr != NULL)
        {
            preptr -> next = ptr -> next;
            free(ptr);
        }
        return start;

    }
};
void display (struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d\t",ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

int main()
{
    struct node *start = NULL;
    start = insert_beg(start,1);
    display(start);
    start = insert_end(start,25);
    display(start);
    start = insert_beg(start,7);
    display(start);
    start = delete_node(start,25);
    start = insert_after(start,4,7);
    display(start);
    start = delete_beg(start);
    display(start);

    return 0;
}
