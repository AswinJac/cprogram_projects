#include <stdio.h>
#include <stdlib.h>
int a[50][50],b[50][50],r1,c1,r2,c2,ta[50][3],tb[50][3],tra[50][3],trb[50][3],s[50][3];
void input(int a[][50],int r,int c);
void tupple(int a[][50],int tup[][3],int r,int c);
void tranpose(int tup[][3],int trans[][3],int r,int c);
void sum(int tupa[][3],int tupb[][3]);
void main()
{

        int ch;
        printf("Enter number of rows of first matrix\n");
        scanf("%d",&r1);
        printf("Enter number of coloumns of first matrix\n");
        scanf("%d",&c1);
        printf("Enter number of rows of second matrix\n");
        scanf("%d",&r2);
        printf("Enter number of coloumns of second matrix\n");
        scanf("%d",&c2);
        while(true)
        {
            printf("Menu Driven\n");
            printf("1:Input\n");
            printf("2:Tupple\n");
            printf("3:Transpose\n");
            printf("4:Sum\n");
            printf("5:Exit\n");
            printf("Enter a choice\n");
            scanf("%d",&ch);
            if(ch==1)
            {
                printf("Input first matrix\n");
                input(a,r1,c1);

                printf("Input second matrix\n");
                input(b,r2,c2);

            }
            else if(ch==2)
            {
                printf("Tupple foram of first matrix\n");
                tupple(a,ta,r1,c1);
                printf("Tupple form of second matrix\n");
                tupple(b,tb,r2,c2);
            }
            else if(ch==3)
            {
                printf("Transpose of first matrix\n");
                tranpose(ta,tra,r1,c1);
                printf("Tranpose of Second matrix\n");
                tranpose(tb,trb,r2,c2);

            }
            else if(ch==4)
            {
                printf("Sum of matrix\n");
                sum(ta,tb);
            }
            else if(ch==5)
            {
                exit(0);
            }
            else
                printf("InvalidChoice");
        }
    }
void input(int a[][50],int r,int c)
{
    printf("Enter elements\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void tupple(int a[][50],int tup[][3],int r,int c) {
    tup[0][0]=r;
    tup[0][1]=c;
    int k=1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(a[i][j]!=0)
            {
                tup[k][0]=i;
                tup[k][1]=j;
                tup[k][2]=a[i][j];
                k=k+1;
            }
        }
    }
    tup[0][2]=k-1;}
    void tranpose(int tup[][3],int trans[][3],int r,int c)
    {
    trans[0][0]=tup[0][1];
    trans[0][1]=tup[0][0];
    int k=1;
    for(int i=0;i<tup[0][1];i++)
    {
        for(int z=1;z<=tup[0][2];z++)
        {
            if(i==tup[z][1])
            {
                trans[k][0]=i;
                trans[k][1]=tup[z][0];
                trans[k][2]=tup[z][2];
                k++;
            }
        }
    }
    trans[0][2]=k-1;
    }
    void sum(int tupa[][3],int tupb[][3])
    {
    int i=0,j=0;
    int l1=tupa[0][2];
    int l2=tupb[0][2];
    while(i<l1 && j<l2)
    {

    }

    }