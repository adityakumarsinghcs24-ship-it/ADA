#include<stdio.h>

int partition(int arr[],int l,int r){
    int i=l+1,j=r,p=arr[l];
    while(i<=j){
        while(i<=r && arr[i]<=p)i++;
        while(arr[j]>p)j--;
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            
        }  
    }
    int temp=arr[l];
    arr[l]=arr[j];
    arr[j]=temp;
    return j;
    
}
void qs(int arr[],int l,int r){
    if(l<r){
        int p=partition(arr,l,r);
        qs(arr,l,p-1);
        qs(arr,p+1,r);
    }
}
int main(){
    int n;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("ENTER:\n");
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    qs(arr,0,n-1);
    printf("Sorted array\n");
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
}
