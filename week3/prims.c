//program to implement Prims Algorithm:
#include<stdio.h>
#include<stdlib.h>
#define V 5
#define INF 999
int minkey(int key[],int mstset[])
{
    int min=INF, minind=-1;
    for(int i=0;i<V;i++)
    {
        if(!mstset[i] && key[i]<min)
        {
            min=key[i];
            minind=i;
        }
    }
    return minind;
}

void prims(int graph[V][V])
{
    int* key=(int*)malloc(V*sizeof(int));
    int* parent=(int*)malloc(V*sizeof(int));
    int* mstset=(int*)calloc(V,sizeof(int));

    for(int i=0;i<V;i++)
    {
        key[i]=INF;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<V-1;i++)
    {
        int u=minkey(key,mstset);
        mstset[u]=1;

        for(int v=0;v<V;v++)
        {
            if(!mstset[v] && graph[u][v] && key[u]!=INF && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

    printf("the minimum spanning tree according to prims Algorithm is:\n");
    int sum=0;
    for (int i = 1; i < V; i++) {
    printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    sum += graph[i][parent[i]];
    }
    printf("\nthe total cost %d",sum);
}

int main()
{
    int graph[V][V]={
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    prims(graph);
    return 0;
}