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
void push1(struct node *n,int data);
void changeValue(struct node *n);

int main()
{
    // declaration of nodes
    struct node *head =NULL;
    struct node *node2 =NULL;
    struct node *node3 =NULL;
    printf("head = %p \n",head);
    printf("&head = %p \n",&head);

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

    printf("head=%p &head=%p *head=%d\n",head,&head,*head);


    printNode(head); //pass by reference
    changeValue(head); //pass by reference
    printNode(head); //pass by reference
    push1(head,10);
    printf("head=%p\n",head);
    printNode(head); //pass by reference
    push(&head,20); //pass by reference
    printNode(head); 


 /*   push1(head,10);

    printNode(head);
   push(&head,10);
    printNode(head);
*/
    free(head);
    free(node2);
    free(node3);



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

void push(struct node **n,int data1)
{
    printf("push &n=%p \n",&n);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data1;
    newNode->next = (*n);
    printf("push: [%p %p %p] \n ",n,(*n),(**n));
    (*n) = newNode;

}
void push1(struct node *n,int data1)
{
    printf("push1 &n=%p \n",&n);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data1;
    newNode->next = n;
   // printf("push1: [n=%p *n=%pp newNode=%p] \n ",n,(*n),newNode);
    printf("push1[passed value] n=%p *n=%d\n",n,*n);
    n = newNode;
    printf("push1[changed value] n=%p *n=%d\n",n,*n);
    printNode(n);

}

void changeValue(struct node *n)
{

    n->data=200;
}
