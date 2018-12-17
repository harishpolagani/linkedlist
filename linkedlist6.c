// write a program to detect a loop in a linkedlist.
// once loop is detected we need to find the joint node
// After finding the joint node remove the loop withe joint node

#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};

void push(struct node **headRef,int data);
void printList(struct node *headRef);
void detectLoop(struct node *headRef);
void removeLoopNode(struct node *headRef,struct node *cnode);
void deleteList(struct node **headRef);

int main(){
    struct node *head = NULL;

    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    printList(head);
    detectLoop(head);

    //add a loop
    printf("head->next->next->next->next->data: %d \n",head->next->next->next->next->data);
    printf("head->next->next->next->next->data: %d \n",head->next->next->data);
    head->next->next->next->next->next = head->next->next;
    printList(head);
    //detect and remove loop
    detectLoop(head);
    printList(head);


    deleteList(&head);

    return 0;
}

//push the node at front of list
void push(struct node **headRef,int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next = NULL;

    newnode->next = (*headRef);
    (*headRef)=newnode;
}

void printList(struct node *headRef)
{
    int count =10;
    while(headRef !=NULL && count>0 )
    {
        printf("%d ",headRef->data);
        headRef = headRef->next;
        count--;
    }
    printf("\n");
}

void deleteList(struct node **headRef)
{
    struct node *curr=NULL,*prev=NULL;
    curr=prev=(*headRef);

    while(curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    //dereference the head node
    (*headRef)=NULL;
}

//floyds cycle detection algorithm
void detectLoop(struct node *headRef)
{
    struct node *slowpointer = NULL;
    struct node *fastpointer = NULL;
    slowpointer = fastpointer = headRef;

    //printf("slow pointer= %d \n ",slowpointer->data);
    //printf("fast pointer= %d \n",fastpointer->data);


    while(slowpointer && fastpointer && fastpointer->next)
    {

        slowpointer=slowpointer->next;
        fastpointer=fastpointer->next->next;

        //printf("slow pointer= %d \n",slowpointer->data);
        //printf("fast pointer= %d \n",fastpointer->data);

        if(slowpointer == fastpointer){
            printf("slow pointer == fast pointer \n loop detected \n");
            removeLoopNode(headRef,slowpointer);
            return;
        }
    }
    printf("loop not found \n ");
}

void removeLoopNode(struct node *headRef,struct node *cnode)
{
    struct node *headStartNode =NULL;
    struct node *cnodeStartNode = NULL;
    headStartNode = headRef;
    

    while(1)
    {
        //in each loop reset the common node position
        cnodeStartNode = cnode;
        while(cnodeStartNode->next !=cnode && cnodeStartNode->next != headStartNode)
        {
            //move the cnodeStart node to next node
            cnodeStartNode = cnodeStartNode->next;            
        }
        if( cnodeStartNode->next == headStartNode )
        {
            printf("joint found \n");
            printf("cnodeStartNode node value:%d \n",cnodeStartNode->data);
            printf("headstartnode value:%d \n",headStartNode->data);

            break;
        }
        //move headRef to next node
        headStartNode = headStartNode->next;
        printf(" headStartNode:%d \n",headStartNode->data);
    }
    //remove the loop connection by removing the joint node
    cnodeStartNode->next=NULL;
}

