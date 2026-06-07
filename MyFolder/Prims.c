#include<stdio.h>
#include<limits.h>
#define INF 999
void prims(int graph[10][10],int v){
    int selected[10]={0},totalcost=0;
    int edges=0;
    selected[0]=1;
    printf("path:\n");
    while(edges<v-1){
        int min=INT_MAX;
        int s=-1,d=-1;
        for(int i=0;i<v;i++){
            if(selected[i]){
                for(int j=0;j<v;j++){
                    if(!selected[j]&& graph[i][j]<min){
                        min=graph[i][j];
                        s=i;
                        d=j;
                    }
                }
            }
        }
        printf("%d->%d:%d\n",s,d,min);
        selected[d]=1;
        totalcost+=min;
        edges++;
    }
    printf("Total cost: %d",totalcost);
}
int main(){
    int v;
    printf("Enter no. of vertices: ");
    scanf("%d",&v);
    int graph[10][10];
    printf("Enter cost matrix:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==0)graph[i][j]=INF;
        }
    }
    prims(graph,v);
}
