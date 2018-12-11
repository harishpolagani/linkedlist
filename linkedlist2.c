#include<stdio.h> // for printf functions
#include<stdlib.h> // for malloc and free functions


struct node{
 int data;
 struct node *next;
};

//function declarations
void printNode(struct node *n);
//Adding node at front
void push(struct node **n,int data);
//insert node after
int insertAfter(struct node *,int data);
//insert At End
int insertAtEnd(struct node **,int data);

//delete the specified node
int deleteNode(struct node **,int data);

//delete Full linked list
void emptyList(struct node *n);

int main()
{
    // declaration of nodes
    struct node *head =NULL;
    struct node *node2 =NULL;
    struct node *node3 =NULL;
   // printf("head = %p \n",head);
   // printf("&head = %p \n",&head);

    //definition of nodes [ memory allocations ]
    head = (struct node *)malloc(sizeof(struct node));
    node2 = (struct node *)malloc(sizeof(struct node));
    node3 = (struct node *)malloc(sizeof(struct node));

    //head = head;
    head->data = 1;
    head->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next =NULL;

   // printf("head=%p &head=%p *head=%d\n",head,&head,*head);

    printNode(head); //pass by reference
    push(&head,20); //pass by reference
    printNode(head); //pass by reference
    insertAfter(head->next,8);
    printNode(head);

    deleteNode(&head,3);
    printNode(head);

    insertAtEnd(&head,400);
    printNode(head); //pass by reference

    //free(head);
   // free(node2);
    //free(node3);

    emptyList(head);


    return 0;
}

void printNode(struct node *n)
{
    while(n != NULL)
    {
  //      printf("[%p ",n);
        printf("[ %d ]",n->data);
        n=n->next;
    }
    printf(" \n");

}

//Add new node at the begining of Head node i.e.. Add node at front 
void push(struct node **n,int data1)
{
  //  printf("push &n=%p \n",&n);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data1;
    newNode->next = (*n);
   // printf("push: [%p %p %p] \n ",n,(*n),(**n));
    (*n) = newNode;

}

int  insertAfter(struct node *n,int data1)
{
    if(n == NULL)
    {
        printf("given node can not be NULL\n");
        return -1;
    }
    struct node *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data=data1;
    newNode->next=n->next;
    n->next=newNode;
}

int insertAtEnd(struct node **head_ref,int data1)
{
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data1;
    newNode->next=NULL;

    if((*head_ref)==NULL)
    {
        (*head_ref)=newNode;
        return 0;
    }

    struct node *last=NULL;
    last= (*head_ref);
    while(last->next != NULL)
    {
        last=last->next;
    }

    last->next=newNode;


}

void emptyList(struct node *n)
{
    //if head node is NULL
    if(n == NULL)
    {
        return;
    }

    //Head node is not NULL
    //check for other nodes
    struct node *current=NULL;
    

    while(n->next!=NULL)
    {
        current=n;
        n=n->next;
        free(current);

    }
    //delete the last node
    free(n);

}

int deleteNode(struct node **n,int data1)
{
    struct node *temp=(*n),*prev;//temp=head node
    prev=temp;//temp1=head node
    
    //node to be deleted is first node
    if(temp!=NULL && temp->data==data1)
    {
        //Head node changed to second node
        (*n) = temp->next; 
        free(temp);
        return 0;
    }

    //if node to be deleted is other than first node

    while(temp != NULL && temp->data != data1)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp == NULL)
    {
        printf("data not found in list \n");
        return 0;
    }

    //Here temp! =NUll then data == data1 --> key matched
    //link the previous node and next node
    prev->next=temp->next;

    free(temp);

    return 0;
}
