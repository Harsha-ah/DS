#include<stdio.h>
#include<stdlib.h>
#define INF 999
int main()
{
    int adj[10][10],visited[10],i,j,s,n,ne=0,tot=0;
    printf("enter no.of vertices:");
    scanf("%d",&n);
    printf("enter adjacency matrix:");
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==0)
            adj[i][j]==INF;
        }
    }
    printf("enter the starting vertex:");
    scanf("%d",&s);
    visited[s]=1;
    while(ne<n-1)
    {
        int min=INF,a=0,b=0;
        for(i=1;i<=n;i++)
        {
            if (visited[i]==1)
            {
                for(j=1;j<=n;j++)
                {
                    if(visited[j]==0&&adj[i][j]!=INF)
                    {
                        if(adj[i][j]<min)
                        {
                            min=adj[i][j];
                            a=i;
                            b=j;
                        }
             
                    }
                }
            }
            
        }
        printf("the edge %d->%d:Cost=%d\n",a,b,min);
        visited[b]=1;
        ne++;
        tot+=min;
    }
    printf("total cost of minimum spanning tree:%d\n",tot);
    return 0;
}