#include <stdio.h>
#include <stdlib.h>
struct tree{
    int data;
    struct tree *left,*right;
};
struct tree *create();
void inorder(struct tree *a);
void postorder(struct tree *a);
void preorder(struct tree *a);
void main()
{
    int ch;
    printf("Enter Root");
    struct tree *root;
    root=0;
    root=create();
    while(true)
    {
        printf("Menu Driven\n");
        printf("1:InOrder\n");
        printf("2:PostOrder\n");
        printf("3:Preorder\n");
        printf("Enter Choice");
        scanf("%d",&ch);
        if(ch==1)
        {
            inorder(root);
        }
        else if(ch==2)
        {
            postorder(root);
        }
        else if(ch==3)
        {
            preorder(root);

        }
        else
            exit(0);
    }
}
struct tree *create()
{
    struct tree *newnode;
    newnode=(struct tree*)malloc(sizeof(struct tree));
    int x;
    printf("Enter data and -1 for no node\n");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    newnode->data=x;
    printf("Enter Left child for %d",x);
    newnode->left=create();
    printf("Enter Right Child for %d",x);
    newnode->right=create();
    return newnode;
}
void inorder(struct tree *a)
{
    if(a!=NULL)
    {
        inorder(a->left);
        printf("%d ",a->data);
        inorder(a->right);
    }
}
void postorder(struct tree *a)
{
    if(a!=NULL)
    {
        postorder(a->left);
        postorder(a->right);
        printf("%d ",a->data);
    }
}
void preorder(struct tree *a)
{
    if(a!=NULL)
    {
        printf("%d ",a->data);
        preorder(a->left);
        preorder(a->right);
    }
}