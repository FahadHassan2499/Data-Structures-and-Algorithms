#include <stdio.h>
void dispArr(int *arr, int n);
void bubbleSort(int *arr,int n);
int main()
{
    int arr[] = {5,1,4,2,8};
    int size = sizeof(arr) / sizeof(int);
    dispArr(arr, size);
    bubbleSort(arr,size);
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

void bubbleSort(int *arr,int n){
    int temp,isSorted=0;
    for(int i=0; i<n-1; i++){
        printf("Pass %d\n",i+1);
        isSorted=1;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted=0;
            }
            
        }
        if(isSorted)
                return;
    }
}