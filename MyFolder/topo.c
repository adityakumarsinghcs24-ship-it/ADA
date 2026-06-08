#include<stdio.h>
#define MAX 100
void topo(int n,int adj[MAX][MAX]){
    int indegree[MAX]={0},count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[j][i]==1)indegree[i]++;
        }
    }
    printf("Topo order\n");
    while(count<n){
        int found=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                printf("%d ",i);
                found=1;
                count++;
                indegree[i]=-1;
                for(int j=0;j<n;j++){
                    if(adj[i][j]==1)indegree[j]--;
                }
            }
        }
        if(!found)printf("CYCLE");
    }
    printf("\n");
}
int main(){
    int n,e,u,v;
    printf("Enter no. of vertices and edges: ");
    scanf("%d%d",&n,&e);
    int adj[MAX][MAX];
    printf("Enter u v: \n");
    
        for(int j=0;j<e;j++){
            scanf("%d%d",&u,&v);
            adj[u][v]=1;
        }
inp: 4 4
0 1
0 2
1 3
2 3
Topo order
0 1 2 3 

    topo(n,adj);
}
