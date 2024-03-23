#include <stdio.h>
#include <stdlib.h>
int front=-1,rear=-1,cirsize,priosize,que[20];
void addcir();
void display();
void deletecir();
void addprio();
void displayprio();
void deleteprio();
void main()
{
    int ch;
    printf("Enter  size of Circular queue\n");
    scanf("%d",&cirsize);
    printf("Enter  size of Priority queue\n");
    scanf("%d",&priosize);
    while(true)
    {
        printf("Menu Driven\n");
        printf("1:Add element in circular queue\n");
        printf("2:Delete element in circular queue\n");
        printf("3:Add element in Priority queues\n");
        printf("4:Delete element in priority queue\n");
        printf("Enter a choice\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            addcir();
            display();
        }
        else if(ch==2)
        {
            deletecir();
            display();
        }
        else if(ch==3)
        {
            addprio();
            displayprio();
        }
        else if(ch==4)
        {
            deleteprio();
            displayprio();
        }
        else if(ch==5)
        {
            exit(0);
        }
        else
            printf("InvalidChoice");
    }
}
void addcir()
{
    int num;
    printf("Enter an element\n");
    scanf("%d",&num);
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        que[rear]=num;
    }
    else if((rear+1)%cirsize==front)
    {
        printf("Ques Full\n");
    }
    else
    {
        rear=(rear+1)%cirsize;
        que[rear]=num;
    }
}
void display()
{
    for(int i=front;i!=rear;i=(i+1)%cirsize)
        printf("%d  ",que[i]);
    printf("%d  \n",que[rear]);
}
void deletecir()
{
    if(front==-1 && rear==-1)
    {
        printf("Emppty\n");


    }
    else if(front==rear)
    {
        printf("Element deleted : %d\n",que[front]);
        front=rear=-1;
    }
    else
    {
        printf("Element deleted : %d\n",que[front]);
        front=(front+1)%cirsize;
    }
}
struct  node
{
    int data;
    int prio;
};
struct node element[20];
void addprio()
{
    int p,d;
    printf("Enter data\n");
    scanf("%d",&d);
    printf("Enter priority\n");
    scanf("%d",&p);
    if(rear==priosize-1)
        printf("Full\n");
    else if(rear==-1 && front==-1)
    {
        front=rear=0;
        element[rear].data=d;
        element[rear].prio=p;
    }
    else
    {
        rear=rear+1;
        element[rear].data=d;
        element[rear].prio=p;
    }
    for(int i=rear;i>front;i--) {
        if(element[i].prio > element[i- 1].prio) {
            struct node temp;
            temp=element[i];
            element[i]=element[i-1];
            element[i-1]=temp;

        }}
}
void displayprio()
{
    if(front==-1 && rear==-1)
    {
        printf("Empty\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d[%d]",element[i].data,element[i].prio);
        }
    }

}
void deleteprio()
{
   if(front==-1 && rear==-1)
       printf("Empty\n");
   else if(front==rear)
   {
       printf("Element deleted %d\n",element[front].data);
       front=rear=-1;
   }
   else
   {
       printf("Element deleted %d\n",element[front].data);
       front=front+1;
   }
}