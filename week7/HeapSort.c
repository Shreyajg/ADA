//program to implement heap sort:
#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void heapify(int a[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[largest])
    {
        largest=left;
    }
    if(right<n && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&a[largest],&a[i]);
        heapify(a,n,largest);
    }
    
}

void heapsort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(&a[i],&a[0]);
        heapify(a,i,0);
    }
}

int main()
{
    int a[]={5,8,2,0,1};
    heapsort(a,5);
    printf("Sorted Array:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}