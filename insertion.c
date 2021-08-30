#include <stdio.h>
void insLast(int arr[], int a);
void insStart(int arr[], int a);
void insBetween(int arr[], int a,int c);
int main()
{
    int a[10] = {1, 5, 6, 7};
    int e = 8;
    insLast(a, e);
    printf("Insertion at the end\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
    int x = 9;
    insStart(a, x);
    printf("Insertion at the beginning\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", a[i]);
    }
    int y = 10;
    int j=3;
    insBetween(a,y,j);
    printf("Insertion at a specific position\n");
    for(int i=0 ; i<7 ; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}

void insLast(int arr[], int a)
{
    arr[4] = a;
}

void insStart(int arr[], int a)
{
    for (int i = 5; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = a;
}

void insBetween(int arr[],int a,int c){
    for(int i=6 ; i>c-1; i--){
        arr[i]=arr[i-1];
    }
    arr[c-1] = a;
}