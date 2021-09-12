#include <stdio.h>
void dispArr(int *arr, int n);
void insertionSort(int *arr,int n);
int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(arr) / sizeof(int);
    dispArr(arr, size);
    insertionSort(arr,size);
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

void insertionSort(int *arr, int n){
    int j, temp;
    for(int i=0; i<n-1; i++){
        j=i+1;
        while(arr[j]<arr[j-1]&&j>0){
            temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j] = temp;
            j--;
        }
    }
}