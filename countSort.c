#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void dispArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int maximum(int a[],int n){
    int Max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>Max)
            Max=a[i];
    }
    return Max;
    
}
void countSort(int a[],int n){
    int max = maximum(a,n);
    int *count = (int *)malloc((max+1)*sizeof(int));
    for(int i=0; i<max+1 ; i++){
        count[i]=0;
    }
    for (int i = 0; i < n; i++){
        count[a[i]]=count[a[i]]+1;
    }
    int i=0;
    int j=0;
    while(i<max+1){
        if(count[i]>0){
            a[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
    
}

int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(arr) / sizeof(int);
    dispArr(arr, size);
    countSort(arr,size);
    printf("Array after sort\n");
    dispArr(arr,size);
    return 0;
}