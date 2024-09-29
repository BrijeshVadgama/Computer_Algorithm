#include <stdio.h>

int binary_search(int a[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void main()
{
    int size, i, key, ans;

    printf("Enter How Many Array Elements Do You Want: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter Array Elements: \n");

    for (i = 0; i < size; i++)
    {
        printf("Enter Element %d: ", (i + 1));
        scanf("%d", &arr[i]);
    }

    printf("Enter Which Element Do You Find: ");
    scanf("%d", &key);

    ans = binary_search(arr, 0, size, key);

    if (ans == -1)
    {
        printf("Element Not Fount.!");
    }
    else
    {
        printf("Element is Found at %d", ans);
    }
}
