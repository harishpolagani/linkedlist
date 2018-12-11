//Find Length of a Linked List (Iterative)

#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};


void push(struct node **,int data);
int countList(struct node *);
int countRecursive(struct node *);
void deleteList(struct node **);
void printList(struct node *);

int main()
{
    struct node *head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    printList(head);
    
    //iterative method
    printf("iterative count=%d \n", countList(head));

    //recursive method
    printf("recursive count=%d \n",countRecursive(head));

    deleteList(&head);


    return 0;
}
void push(struct node **headRef,int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    //if list is empty
    if((*headRef == NULL))
    {
        (*headRef)=new_node;
        return;
    }
    new_node->next=(*headRef);
    (*headRef)=new_node;
}

int countList(struct node *headRef)
{
    int count =0;
    while(headRef != NULL)
    {
        count++;
        headRef = headRef->next;
    }
    return count;
}

void deleteList(struct node **headRef)
{
    struct node *prev=NULL,*curr=NULL;
    prev = curr = (*headRef);
    if(curr == NULL )
    {
        printf("list is Empty \n");
        return;
    }
    while(curr != NULL)
    {
        prev = curr;
        curr=curr->next;
        free(prev);
    }

    //removing the head reference in main fun
    free(*headRef);
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
int countRecursive(struct node *headRef)
{
    if(headRef == NULL)
        return 0;
    else
        return 1 + countRecursive(headRef->next);
}
