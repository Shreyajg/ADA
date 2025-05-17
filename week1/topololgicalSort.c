#include<stdio.h>
#include<stdlib.h>

int* topologicalsort(int** Matrix,int matrixSize)
{
    int* indegree=(int*)calloc(matrixSize,sizeof(int));

    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<matrixSize;j++)
        {
            if(Matrix[i][j]==1)
            {
                indegree[j]++;
            }
        }
    }

    int* queue=(int*)malloc(matrixSize*sizeof(int));
    int front=0,rear=0;
    for(int i=0;i<matrixSize;i++)
    {
        if(indegree[i]==0)
        {
            queue[rear++]=i;
        }
    }
    int k=0;
    int* result=(int*)malloc(matrixSize*sizeof(int));
    while(front<rear)
    {
        int curr=queue[front++];
        result[k++]=curr;
        for(int i=0;i<matrixSize;i++)
        {
            if(Matrix[curr][i]==1)
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    queue[rear++]=i;
                }
            }
        }
    }
    free(queue);
    free(indegree);
    return result;
}

int main()
{
    printf("enter the number of vertices:\n");
    int n;
    scanf("%d",&n);
    int** Matrix=(int**)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        Matrix[i]=(int*)malloc(n*sizeof(int));
    }
    printf("enter the adjacency matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&Matrix[i][j]);
        }
    }

    int* result=(int*)malloc(n*sizeof(int));
    result=topologicalsort(Matrix,n);
    printf("Sorted:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }
    return 0;
}