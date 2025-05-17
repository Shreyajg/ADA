//Program to implement MergeSort:
#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int* left=(int*)malloc(n1*sizeof(int));
    int* right=(int*)malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++)
    {
        left[i]=a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        right[j]=a[m+1+j];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k++]=left[i++];
        }
        else{
            a[k++]=right[j++];
        }
    }
    while(i<n1)
    {
        a[k++]=left[i++];
    }
    while(j<n2)
    {
        a[k++]=right[j++];
    }
}

void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main()
{
    int a[]={5,2,9,3,7};
    mergesort(a,0,4);
    printf("Sorted Array:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}