#include <stdio.h>
#include<stdlib.h>
#define MAX 50
int board[20],size;
int isSafe(int row,int col){
    for(int i=1;i<row;i++){
        if(board[i]==col)return 0;
        if(abs(board[i]-col)==abs(i-row))return 0;
        
    }
    return 1;
}
void solve(int row){
    int col;
    for(col=1;col<=size;col++){
        if(isSafe(row,col)){
            board[row]=col;
            if(row==size){
                printf("Solution\n");
                for(int i=1;i<=size;i++)printf("Queen %d-> Column %d\n",i,board[i]);
            }
            else solve(row+1);
        }
    }
}
int main(){
    printf("Enter no. of queens: ");
    scanf("%d",&size);
    solve(1);
}
