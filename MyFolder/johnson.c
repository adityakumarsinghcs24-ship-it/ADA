#include<stdio.h>
int perm[10],dir[10];
void print(int n){
    for(int i=0;i<n;i++)printf("%d ",perm[i]);
    printf("\n");
}
int getmobile(int n){
    int mobile=0,pos=-1;
    for(int i=0;i<n;i++){
        int next=i+dir[i];
        if(next>=0 && next<n && perm[next]<perm[i]){
            if(perm[i]>mobile){
                mobile=perm[i];
                pos=i;
            }
        }
    }
    return pos;
}
void johnson(int n){
    for(int i=0;i<n;i++){
        perm[i]=i+1;
        dir[i]=-1;
    }
    print(n);
    while(1){
        int mob=getmobile(n);
        if(mob==-1)break;
        int swapos=mob+dir[mob];
        int temp=perm[swapos];
        perm[swapos]=perm[mob];
        perm[mob]=temp;
        temp=dir[swapos];
        dir[swapos]=dir[mob];
        dir[mob]=temp;
        mob=swapos;
        for(int i=0;i<n;i++){
            if(perm[i]>perm[mob])dir[i]*=-1;
        }
        print(n);
    }
}
int main(){
    int n;
    printf("Enter n; ");
    scanf("%d",&n);
    johnson(n);
}
