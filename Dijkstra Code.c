#include<stdio.h>
#define INF 9999

void dijkstra(int graph[10][10],int n, int s){
    int d[10],v[10],min,u;
    for(int i=0;i<n;i++){
        d[i]=graph[s][i];
        v[i]=0;
    }
    v[s]=1;
    d[s]=0;
    for(int i=1;i<n;i++){
        min=INF;
        for(int j=0;j<n;j++){
            if(!v[j] && d[j]<min ){
                min=d[j];
                u=j;
            }
        }
        v[u]=1;
        for(int j=0;j<n;j++){
            if(!v[j] && d[u]+graph[u][j]<d[j]){
                d[j]=d[u]+graph[u][j];
            }
        }
    }
    
    printf("Shortest Distance: \n");
    for(int i=0;i<n;i++){
        printf("%d->%d: %d\n",s,i,d[i]);
    }
}
int main(){
    int n;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    int graph[10][10];
    printf("Enter cost matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==0 && i!=j)graph[i][j]=INF;
        }
    }
    int s;
    printf("Enter src vertex: ");
    scanf("%d",&s);
    dijkstra(graph,n,s);
}
