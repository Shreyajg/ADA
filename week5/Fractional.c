//program to implement Fractional Knapsack:
#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int fractional(int n,int weight[],int value[],int capacity)
{
    int* ratio=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        ratio[i]=(float)value[i]/weight[i];
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(ratio[j]>ratio[j+1])
            {
                swap(&ratio[j],&ratio[j+1]);
                swap(&weight[j],&weight[j+1]);
                swap(&value[j],&value[j+1]);
            }
        }
    }
    float totval=0.0;
    for(int i=0;i<n && capacity>0;i++)
    {
        if(weight[i]<=capacity)
        {
            capacity-=weight[i];
            totval+=value[i];
        }
        else{
            totval+=ratio[i]*capacity;
            capacity=0;
        }
    }
    return totval;
}

int main()
{
    int size, capacity;
    printf("Enter number of items: ");
    scanf("%d", &size);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    int* weight=(int*)malloc(size*sizeof(int));
    int* value=(int*)malloc(size*sizeof(int));
    printf("enter the weight matrix\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&weight[i]);
    }
    printf("enter the value matrix\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&value[i]);
    }
    int res=fractional(size,weight,value,capacity);
    printf("%d ",res);

}