//Write a function to delete a Linked List
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **,int);
void deleteList(struct node **);

int main()
{
    struct node *head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    push(&head,9);
    push(&head,10);

    printList(head);
    deleteList(&head);

    //dangling pointer
    printList(head);

    return 0;
}

//push the element at front
void push(struct node **headRef,int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data= data;
    new_node->next=NULL;

    if((*headRef==NULL))
    {
        //List is NULL this is first element
        (*headRef) = new_node;
        return;
    }
    //if List already has some elements
    //insert node at front
    new_node->next=(*headRef);
    (*headRef)=new_node;   

}

//delete the entire list
void deleteList(struct node **headRef)
{
    if((*headRef) == NULL )
    {
        printf("list is empty \n ");
        return;
    }

    struct node *prev=NULL,*curr=NULL;
    prev=curr=(*headRef);
    while(curr != NULL)
    {
        prev = curr;
        curr=curr->next;
        free(prev);
    }

    //delete the head reference to effect the real head back in main function
    free((*headRef));

}

void printList(struct node *headRef)
{
    while(headRef != NULL )
    {
        printf("%d ",headRef->data);
        headRef=headRef->next;
    }
    printf("\n");
}
