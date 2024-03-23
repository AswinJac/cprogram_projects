#include <stdio.h>
#include <stdlib.h>
struct poly
{
    int exp;
    int co;
    struct poly *link;
};
void input(struct poly **head);
void display(struct poly *head);
void mult(struct poly *head1,struct poly *head2,struct poly **head3);
void main()
{
    struct poly *poly1=NULL,*poly2=NULL,*poly3=NULL;
    int ch;
    while(true)
    {
        printf("\nMenu Driven\n1: Read First Poly\n2: Read Second Poly\n3: Display\n4: Multiply Poly\n5: Exit\n");
        printf("Enter Choice: \n");
        scanf("%d", &ch);
        if(ch==1)
        {
            printf("Enter first polynomial\n");
            input(&poly1);
        }
        else if(ch==2)
        {
            printf("Enter Second polynomial\n");
            input(&poly2);
        }
        else if(ch==3)
        {
            printf("First Polynomial\n");
            display(poly1);
            printf("Second polynomial\n");
            display(poly2);
        }
        else if(ch==4)
        {
            mult(poly1,poly2,&poly3);
            printf("Multiplied polynomial\n");
            display(poly3);

        }
    }
}
void insert(struct poly **head,int coe,int expon);
void input(struct poly **head)
{
    int term;
    printf("Enter number of terms\n");
    scanf("%d",&term);
    for(int i=0;i<term;i++)
    {
    int coeff,expo;
    printf("Enter a coefficient and exponent\n");
    scanf("%d%d",&coeff,&expo);
    insert(head,coeff,expo);}
}
void insert(struct poly **head,int coe,int expon)
{
    struct poly *newnode;
    newnode=(struct poly*) malloc(sizeof(struct poly));
    newnode->exp=expon;
    newnode->co=coe;
    newnode->link=NULL;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        struct poly *ptr=*head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=newnode;
    }
}
void display(struct poly *head)
{
    if(head==NULL)
        printf("Empty");
    else
    {
        struct poly *ptr=head;
        while(ptr!=NULL)
        {
            printf("%dx^%d",ptr->co,ptr->exp);
            if(ptr->link!=NULL)
            {
                printf("+");
            }
            ptr=ptr->link;
        }
        printf("\n");
    }
}
void mult(struct poly *head1,struct poly *head2,struct poly **head3)
{
    *head3=NULL;
    struct poly *ptr1=head1;
    while(ptr1!=NULL)
    {
        struct poly *ptr2=head2;
        while (ptr2!=NULL)
        {
            int exp=ptr1->exp+ptr2->exp;
            int coef=ptr1->co*ptr2->co;
            struct poly *temp=*head3;
            if(temp!=NULL && temp->exp!=exp)
            {
                temp=temp->link;
            }
            if(temp==NULL)
            insert(head3,coef,exp);
            else
                temp->co+=coef;
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
        }}