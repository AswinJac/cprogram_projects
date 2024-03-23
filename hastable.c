#include <stdio.h>
#include <stdlib.h>
struct hash
{
    int data;
    struct hash *link;
};
struct hash *head[10]={NULL};
void insert();
void search(int num);
void display();
void main() {
        int ch,x;
        while (true) {
            printf("1:Insert\n");
            printf("2:Search\n");
            printf("3:Display\n");
            printf("4:Exit\n");
            printf("Enter a choice\n");
            scanf("%d", &ch);
            if (ch == 1)
            {
                insert();
            }
            else if(ch==2)
            {
                printf("Enter a search element\n");
                scanf("%d",&x);
                search(x);
            }
            else if(ch==3)
            {
                printf("___GRAPH___\n");
                display();
            }
            else if(ch==4)
            {
                exit(0);
            }
            else
                printf("InvalidInput\n");


        }
    }
void insert()
{
    int elem;
    printf("Enter an element to insert\n");
    scanf("%d",&elem);
    int index;
    index=elem%10;
    struct hash *newnode;
    newnode=(struct hash *)malloc(sizeof(struct hash));
    newnode->data=elem;
    newnode->link=NULL;
    if(head[index]==NULL)
        head[index]=newnode;
    else
    {
        struct hash *ptr=head[index];
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=newnode;
    }
}
void search(int num)
{
    int ind;
    ind=num%10;
        struct hash *ptr=head[ind];
        while(ptr!=NULL)
        {
            if(ptr->data==num) {
                printf("Element Found\n");
            break;}
            ptr=ptr->link;
        }
        if(ptr==NULL)
            printf("Not ound]\n");


    }


void display()
{
    for(int i=0;i<10;i++)
    {
        printf("H[%d]=",i);
        if(head[i]==NULL)
            printf("Empty\n");
        else
        {
            struct hash *ptr=head[i];
            while(ptr!=NULL)
            {
                printf("%d->",ptr->data);
                ptr=ptr->link;
            }
            printf("\n");
        }}
}
