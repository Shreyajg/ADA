//Program to implement dijkstra's Algorithm:
#include<stdio.h>
#include<stdlib.h>
#define INF 999
int minDistance(int* dist,int* visited,int n)
{
    int mindist=9999,minind=-1;
    for(int i=0;i<n;i++)
    {
        if(dist[i]<mindist && !visited[i])
        {
            mindist=dist[i];
            minind=i;
        }
    }
    return minind;
}

void dijkstra(int graph[10][10],int n,int src)
{
    int* dist=(int*)malloc(n*sizeof(int));
    int* visited=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
    }
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        int u=minDistance(dist,visited,n);
        visited[u]=1;

        for(int i=0;i<n;i++)
        {
            if(!visited[i] && graph[u][i] && (dist[u]+graph[u][i])<dist[i])
            {
                dist[i]=dist[u]+graph[u][i];
            }
        }
    }
    printf("the shortest distance from the source:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",dist[i]);
    }

}

int main() {
    int graph[10][10] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    int n = 9; // Number of vertices
    int src = 0;

    dijkstra(graph, n, src);
    return 0;
}