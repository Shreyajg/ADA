//Program to implement  FLoyds Algorithm:
#include<stdio.h>
#include<stdlib.h>
#define V 4
#define INF 999
void floyds(int graph[V][V])
{
    int dist[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            dist[i][j]=graph[i][j];
        }
    }

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            for(int k=0;k<V;k++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    printf("The min distances are:\n");
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(dist[i][j]==INF)
            {
                printf("INF ");
            }
            else{
                printf("%d ",dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V]={
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };

    floyds(graph);
}