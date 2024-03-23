#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left,*right;
};
struct tree *create(struct tree *root,int data);
void main()
{
    int rootdata,ch;
    struct tree *root=NULL;
    printf("Enter a root");
    scanf("%d",&rootdata);
    root=create(root,rootdata);
    while(true)
    {
        printf("1:Insert elements\n");
        printf("Enter Choice\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            int newdata;
            printf("Enter data");
            scanf("%d",&newdata);
            create(root,newdata);
        }
        else
            exit(0);

    }
}
struct tree *create(struct tree *root,int data)
{
    if(root==NULL)
    {
        struct tree *newnode=(struct tree *) malloc(sizeof(struct tree));
        newnode->data=data;
        newnode->right=newnode->left=NULL;
        return newnode;
    }
    if(data<root->data)
    {
        root->left=create(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=create(root->right,data);
    }
    return root;
}