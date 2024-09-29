// Linear Search in C

#include <stdio.h>

int Linear_Search(int arr[], int size, int n)
{

    for (int i = 0; i < size; i++)
        if (arr[i] == n)
            return i;
    return -1;
}

int main()
{
    int i, size, x;

    printf("Enter How Many Array Elements Do You Want: ");
    scanf("%d", &size);

    int a[size];

    for (i = 0; i < size; i++)
    {
        printf("Enter Element %d: ", (i + 1));
        scanf("%d", &a[i]);
    }

    printf("Enter Which Element Do You Find: ");
    scanf("%d", &x);

    int n = sizeof(a) / sizeof(a[0]);

    int result = Linear_Search(a, n, x);

    if (result == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at index: %d", result);
    }
}