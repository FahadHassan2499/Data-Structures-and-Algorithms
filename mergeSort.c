#include <stdio.h>
#include<stdlib.h>
void dispArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int a[],int low,int mid,int high){
    int i,j,k;
    int b[100];
    i=low;
    k=low;
    j=mid+1;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        b[k]=a[j];
        j++;
        k++;
    }
    for(int i=0; i<=high; i++){
        a[i]=b[i];
    }
}

void mergeSort(int a[],int low,int high){
    int mid;
    if(low<high){
    mid=low+(high-low)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
    }
}



int main()
{
    int arr[] = {10,80,30,90,40,50,70,3,4,67,90,5,6,89,100};
    int size = sizeof(arr) / sizeof(int);
    dispArr(arr, size);
    mergeSort(arr,0,size-1);
    printf("Array after sort\n");
    dispArr(arr,size);
    return 0;
}




// #include <stdio.h>

// void printArray(int *A, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", A[i]);
//     }
//     printf("\n");
// }

// void merge(int A[], int mid, int low, int high)
// {
//     int i, j, k, B[100];
//     i = low;
//     j = mid + 1;
//     k = low;

//     while (i <= mid && j <= high)
//     {
//         if (A[i] < A[j])
//         {
//             B[k] = A[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             B[k] = A[j];
//             j++;
//             k++;
//         }
//     }
//     while (i <= mid)
//     {
//         B[k] = A[i];
//         k++;
//         i++;
//     }
//     while (j <= high)
//     {
//         B[k] = A[j];
//         k++;
//         j++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         A[i] = B[i];
//     }
    
// }

// void mergeSort(int A[], int low, int high){
//     int mid; 
//     if(low<high){
//         mid = (low + high) /2;
//         mergeSort(A, low, mid);
//         mergeSort(A, mid+1, high);
//         merge(A, mid, low, high);
//     }
// }

// int main()
// {
//     // int A[] = {9, 14, 4, 8, 7, 5, 6};
//     int A[] = {10,80,30,90,40,50,70,3,4,67,90,5,6,89,100};
//     int n = 15;
//     printArray(A, n);
//     mergeSort(A, 0, 6);
//     printArray(A, n);
//     return 0;
// }

// /* C program for Merge Sort */
// #include <stdio.h>
// #include <stdlib.h>
 
// // Merges two subarrays of arr[].
// // First subarray is arr[l..m]
// // Second subarray is arr[m+1..r]
// void merge(int arr[], int l, int m, int r)
// {
//     int i, j, k;
//     int n1 = m - l + 1;
//     int n2 = r - m;
 
//     /* create temp arrays */
//     int L[n1], R[n2];
 
//     /* Copy data to temp arrays L[] and R[] */
//     for (i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];
 
//     /* Merge the temp arrays back into arr[l..r]*/
//     i = 0; // Initial index of first subarray
//     j = 0; // Initial index of second subarray
//     k = l; // Initial index of merged subarray
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
 
//     /* Copy the remaining elements of L[], if there
//     are any */
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
 
//     /* Copy the remaining elements of R[], if there
//     are any */
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
 
// /* l is for left index and r is right index of the
// sub-array of arr to be sorted */
// void mergeSort(int arr[], int l, int r)
// {
//     if (l < r) {
//         // Same as (l+r)/2, but avoids overflow for
//         // large l and h
//         int m = l + (r - l) / 2;
 
//         // Sort first and second halves
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);
 
//         merge(arr, l, m, r);
//     }
// }
 
// /* UTILITY FUNCTIONS */
// /* Function to print an array */
// void printArray(int A[], int size)
// {
//     int i;
//     for (i = 0; i < size; i++)
//         printf("%d ", A[i]);
//     printf("\n");
// }
 
// /* Driver code */
// int main()
// {
//     int arr[] = {10,80,30,90,40,50,70,3,4,67,90,5,6,89,100};
//     int arr_size = sizeof(arr) / sizeof(arr[0]);
 
//     printf("Given array is \n");
//     printArray(arr, arr_size);
 
//     mergeSort(arr, 0, arr_size - 1);
 
//     printf("\nSorted array is \n");
//     printArray(arr, arr_size);
//     return 0;
// }