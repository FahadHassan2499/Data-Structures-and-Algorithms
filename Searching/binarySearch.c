#include<stdio.h>

int main(){
    int arr[]={1,7,18,23,33,45,67};
    int a,flag=0;
    printf("Enter the number to be searched\n");
    scanf("%d",&a);
    int n = sizeof(arr)/sizeof(int);
    int low = 0,mid;
    int high = n-1;
    while(low<=high){
    mid = (low+high)/2;
    if(arr[mid]==a){
        flag=1;
        break;
    }
    else if(arr[mid]>a){
        high=mid-1;
    }
    else
        low = mid+1;
    }
    if(flag==1){
        printf("Element found at %d position",mid+1);
    }
    else
        printf("Element not found");

    return 0;
}