#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct pal
{
    char data;
    struct pal *link;
};
struct pal *head=NULL;
struct pal *top=NULL;
int palindrome();
void insert(char ch);
void main()
{
    char s[20];
    printf("Enter a Word\n");
    scanf("%s",s);
    if(s[strlen(s)-1]=='\n')
    {
        s[strlen(s)-1]='\0';
    }
    printf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        insert(s[i]);
    }
    if(palindrome()==1)
        printf("palindrome\n");
    else
        printf("not Palindrome\n");
}
void insert(char ch)
{
    struct pal *newnode=(struct pal*)malloc(sizeof(struct pal));
    newnode->data=ch;
    newnode->link=NULL;
    if(head==NULL)
        head=newnode;
    else{
        struct pal *ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=newnode;
    }
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->link=top;
        top=newnode;
    }

}
int palindrome()
{
    struct pal *ptr=head;
    struct pal *topptr=top;
    while(ptr!=NULL && topptr!=NULL)
    {
        if(ptr->data!=topptr->data)
            return 0;
        ptr=ptr->link;
        topptr=topptr->link;
    }
    return 1;
}