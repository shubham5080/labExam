#include <stdio.h>
#include <time.h>
#define INF 999999

int main(){
    int n,adj[100][100],dist[100],vis[100],src;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);

    scanf("%d",&src);

    for(int i=0;i<n;i++){
        dist[i]=INF;
        vis[i]=0;
    }
    dist[src]=0;

    clock_t s,e; double t;
    s = clock();

    for(int k=0;k<n-1;k++){
        int min=INF,u=-1;
        for(int i=0;i<n;i++)
            if(!vis[i] && dist[i]<min){
                min=dist[i];
                u=i;
            }
        if(u==-1) break;
        vis[u]=1;

        for(int v=0;v<n;v++){
            if(adj[u][v]>0 && !vis[v] && dist[u]+adj[u][v] < dist[v])
                dist[v]=dist[u]+adj[u][v];
        }
    }

    e = clock();
    t = (double)(e-s)/CLOCKS_PER_SEC;

    for(int i=0;i<n;i++)
        if(dist[i]==INF) printf("INF ");
        else printf("%d ",dist[i]);

    printf("\n%f\n",t);
    return 0;
}
