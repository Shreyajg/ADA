//Program to implement Quick Sort:
#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int l,int r)
{
    int i=l-1;
    int p=a[r];
    for(int j=l;j<r;j++)
    {
        if(a[j]<p)
        {
            i++;
            swap(&a[i],&a[j]);
        }
        
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}

void quickSort(int a[],int l,int r)
{
    if(l<r)
    {
        int p=partition(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}

int  main()
{
    int a[]={5,2,8,9,1,0};
    printf("Sorted Array:\n");
    quickSort(a,0,5);
    for(int i=0;i<6;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}