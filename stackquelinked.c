#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL;
struct node *front=NULL;
struct node *rear=NULL;
void push(int num);
int pop();
void display();
void enque(int num);
void dispque();
void deque();
void main()
{int ch;
    while(true)
    {
        printf("Menu Driven\n");
        printf("1:push to stack\n");
        printf("2:pop from stack\n");
        printf("3:enqueue\n");
        printf("4:dequeue\n");
        printf("5:Exit\n");
        printf("Enter a choice\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            int num;
            printf("Enter an element to insert\n");
            scanf("%d",&num);
            push(num);
            display();
        }
        else if(ch==2)
        {
            printf("Element deleted is %d\n",pop());
            display();
        }
        else if(ch==3)
        {
            int numb;
            printf("Enter an element to insert\n");
            scanf("%d",&numb);
            enque(numb);
            dispque();
        }
        else if(ch==4)
        {
            deque();
            dispque();
        }
        else if(ch==5)
            exit(0);


}}
void push(int num)
{
    struct node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num;
    newnode->link=NULL;
    if(top==NULL)
        top=newnode;
    else
    {
        newnode->link=top;
        top=newnode;
    }
}
int pop()
{
    if(top==NULL)
    {
        printf("Empty\n");
        return -1;}
    else
    {
        struct node *ptr=top;
        top=top->link;
        int temp=ptr->data;
        free(ptr);
        return temp;
    }
}
void display()
{
    if(top==NULL)
        printf("Empty\n");
    else
    {
        struct node *ptr=top;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");

    }
}
void enque(int num)
{
    struct node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=num;
    newnode->link=NULL;
    if(front==NULL && rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->link=newnode;
        rear=newnode;
    }
}
void dispque()
{
    if(front==NULL && rear==NULL)
        printf("Empty");
    else
    {
        struct node *ptr=front;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
    }
}
void deque()
{
    if(front==NULL)
    {

        printf("Empty");
        return;
    }
    struct node *ptr=front;
    front=front->link;
    printf("Element deleted %d\n",ptr->data);
    free(ptr);
    if (front == NULL)
        rear = NULL;
}