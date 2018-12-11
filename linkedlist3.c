#include<stdio.h>
#include<stdlib.h>


struct node{
int data;
struct node *next;
};

//push the value at front of list
void push(struct node **,int data);
//delete the node at a given position 
void deleteAtPosition(struct node **,int position);

//print all the nodes in a list
void printList(struct node *n);

int main()
{
    struct node *head=NULL;

    push(&head,1);
    //printList(head);
    push(&head,2);
    //printList(head);
    push(&head,3);
    //printList(head);
    push(&head,4);
    
    printList(head);
    deleteAtPosition(&head,5);
    printList(head);

    //delete the node at a given position 

    return 0;
}

//push the node at front of list
void push(struct node **headRef,int data)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    //if head node is NULL then make this node as head node 
    if((*headRef) == NULL)
    {
        printf("head node is empty \n ");
        (*headRef)=new_node;
        return;
    }

    printf("head node is not null \n ");
    //if head node is not NULL i.e.. list is not empty
    new_node->next = (*headRef);
    (*headRef) = new_node; 
    
    //printList((*headRef));

}

//print the full list
void printList(struct node *n)
{
    //check if list is empty
    if(n == NULL)
    {
        printf("list is empty");
        return;
    }

    //if list has some elements
    while(n != NULL)
    {
        printf("%d ",n->data);
        n=n->next;
    }
    printf(" \n ");
}


void deleteAtPosition(struct node **headRef,int position)
{
    struct node *prev = NULL;
    struct node *curr=NULL;

    //check if head node is NULL 
    if( (*headRef) == NULL )
    {
        printf("list is empty can not delete elements in list");
    }
    
    //position can not be negative number
    if(position <=0 )
    {
        printf("position can not be negative/zero number \n");
        return;
    }

    //check if position is zero, we need to delete the head node and make second node as head node
    if(position == 1 )
    {
        prev = (*headRef);
        (*headRef) = prev->next;
        free(prev);
        return;
    }

    //if postiton is > zero
    int currentPosition =1;
    prev=(*headRef);
    curr = (*headRef);

    while(currentPosition < position && curr !=NULL )
    {
        printf("current position = %d ",currentPosition);
        currentPosition ++;
        prev = curr;
        curr = curr->next;
    }
    //Here we are at desired position 
    if(curr == NULL)
    {
        printf("\n we have reached the end of list, desired position is beyond the list count \n ");
        return;
    }
    printf("desired postion= %d \n",currentPosition);
    prev->next=curr->next;
    free(curr);
   
}
