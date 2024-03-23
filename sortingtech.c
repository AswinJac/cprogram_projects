#include <stdio.h>
#include <stdlib.h>
int a[15],b[15],i,j;
int n;
void input();
void display();
void quicksort(int a[],int lb,int ub);
void mergesort(int a[],int lb,int ub);
void heapsort(int a[],int n);
void main()
{
    int ch;
    while(true)
    {
        printf("MENU DRIVEN\n1:QuickSort\n2:MergeSort\n3:HeapSort\n4:Exit\n");
        printf("Enter a choice\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            input();
            printf("Before Sorting\n");
            display();
            quicksort(a,0,n-1);
            printf("After Sorting\n");
            display();
        }
        else if(ch==2)
        {
            input();
            printf("Before Sorting\n");
            display();
            mergesort(a,0,n-1);
            printf("After Sorting\n");
            display();
        }
        else if(ch==3)
        {
            input();
            printf("Before Sorting\n");
            display();
            heapsort(a,n);
            printf("After Sorting\n");
            display();
        }
        else if(ch==4)
            exit(0);
        else
            printf("InvalidChoice\n");
    }
}
void input()
{

    printf("Enter a number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display()
{
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int partition(int a[],int lb,int ub);
void quicksort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
int partition(int a[],int lb,int ub)
{
    int temp;
    int pivot=a[lb];
    i=lb;
    j=ub;
    while(i<j)
    {
        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;

        }
        temp=a[lb];
        a[lb]=a[j];
        a[j]=temp;
        return j;
    }
}
void mergify(int a[],int lb,int mid,int ub);
void mergesort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=lb+(ub-lb)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        mergify(a,lb,mid,ub);
    }
}
void mergify(int a[],int lb,int mid,int ub)
{
    i=lb;
    j=mid+1;
    int k=lb;
    while(i<=mid&&j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=ub)
        {
            b[k]=a[j];
            k++;
            j++;
        }
    for(int x=lb;x<=ub;x++)
    {
        a[x]=b[x-lb];
    }
}
void heapify(int a[],int n,int i);
void heapsort(int a[],int n) {
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (i = n - 1; i >= 0; i--) {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapify(a, i, 0);
    }
}
void heapify(int a[],int n,int i)
{
    int large;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]>a[i])
    {
        large=l;
    }
    else
        large=i;
    if(r<n&&a[r]>a[large])
        large=r;
    if(large!=i)
    {
        int temp=a[large];
        a[large]=a[i];
        a[i]=temp;
        heapify(a,n,large);
    }



}