#include <stdlib.h>
#include <stdio.h>
struct merge
{
    int data;
    struct merge *link;
};
void insert(struct merge **head);
void display(struct merge *head);
struct merge *list1=NULL,*list2=NULL;
void  mergify(struct merge *head1,struct merge *head2);
void sort(struct merge *head);
void repeat(struct merge *head);
void main()
{
    int ch;
    while(true)
    {
        printf("MenuDriven\n1:Enter elements in first list\n2:Enter elements in second list\n3:Merge elements\n4:Sort elements\n5:Exit\n6:Display\n7:Remove repeating elements\nEnter a choice\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            insert(&list1);
        }
        else if(ch==2)
        {
            insert(&list2);
        }
        else if(ch==3)
        {
            mergify(list1,list2);
            display(list1);
        }
        else if(ch==4)
        {
            sort(list1);
            display(list1);
        }
        else if(ch==5)
        {
            exit(0);
        }
        else if(ch==6)
        {
            display(list1);
            display(list2);
        }
        else if(ch==7)
        {
            repeat(list1);
            display(list1);
        }
    }
}
void insert(struct merge **head)
{
    int elem;
    printf("Enter an element");
    scanf("%d",&elem);
    struct merge *newnode=(struct merge *) malloc(sizeof(struct merge));
    newnode->data=elem;
    newnode->link=NULL;
    if(*head==NULL)
        *head=newnode;
    else
    {
        struct merge *ptr=*head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=newnode;
    }
}
void display(struct merge *head)
{
    if(head==NULL)
        printf("Empty");
    else
    {
        struct merge *ptr=head;
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
void  mergify(struct merge *head1,struct merge *head2)
{
    struct merge *ptr1=head1;
    while(ptr1->link!=NULL)
    {ptr1=ptr1->link;
    }
    ptr1->link=head2;
       // ptr2=ptr2->link;
    }
void sort(struct merge *head)
{
    struct merge *current=NULL;
    if(head==NULL)
        return;
    while(head!=NULL)
    {
        current=head->link;
        while (current!=NULL)
        {
            if(head->data>current->data)
            {
                int temp=head->data;
                head->data=current->data;
                current->data=temp;

            }current=current->link;
        }head=head->link;
    }
}
void repeat(struct merge *head)
{
    struct merge *current=head;
    if(head==NULL)
        return;
    while(current->link!=NULL)
    {
        if (current->link->data == current->data)
        {
            struct merge *temp=current->link;
            current->link=current->link->link;
            free(temp);
        }
        else
        {current=current->link;}
    }

}