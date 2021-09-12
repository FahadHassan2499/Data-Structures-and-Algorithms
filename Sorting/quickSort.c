#include <stdio.h>
void dispArr(int *arr, int n);
void quickSort(int *arr,int low,int high);
int partition(int *arr,int low,int high);
int main()
{
    int arr[] = {10,80,30,90,40,50,70,3,4,67};
    int size = sizeof(arr) / sizeof(int);
    dispArr(arr, size);
    quickSort(arr,0,size-1);
    printf("Array after sort\n");
    dispArr(arr,size);
    return 0;
}

void dispArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void quickSort(int *arr,int low, int high){
    int partitionIndex;
    if(low<high){
    partitionIndex=partition(arr,low,high);
    quickSort(arr,low,partitionIndex-1);
    quickSort(arr,partitionIndex+1,high);
    }
}


int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
    while(arr[i]<=pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }
    if(i<j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    }while(i<j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}