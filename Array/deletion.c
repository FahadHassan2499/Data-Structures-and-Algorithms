#include <stdio.h>

void disp(int arr[], int x);
void delBeg(int arr[], int x);
void delPos(int arr[], int x, int j);

int main()
{
    int a[100], n, c, j;
    printf("Enter number of elements in array\n");
    scanf("%d", &n);
    printf("Enter the elements in the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Menu\n");
    printf("1.Deletion of last element\n");
    printf("2.Deletion of element at the beginning\n");
    printf("3.Deletion of element at a specified position\n");
    printf("Enter choice\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        n -= 1;
        break;
    case 2:
        delBeg(a, n);
        n -= 1;
        break;
    case 3:
        printf("Enter position\n");
        scanf("%d", &j);
        delPos(a, n, j);
        n -= 1;
        break;
    default:
        printf("Wrong option entered");
    }
    disp(a, n);

    return 0;
}

void disp(int arr[], int x)
{
    printf("Final Array is\n");
    for (int i = 0; i < x; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void delBeg(int arr[], int x)
{
    for (int i = 0; i < x; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void delPos(int arr[], int x, int j)
{
    for (int i = j - 1; i < x - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}