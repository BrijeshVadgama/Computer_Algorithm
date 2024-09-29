#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// =============== LINEAR SEARCH ===============

int Linear_Search(int arr[], int size, int n)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == n)
            return i;
    return -1;
}

// =============== BINARY SEARCH ===============

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

// =============== MAIN FUNCTION ===============

void main()
{

    int size, i, choice, x, key, ans;

    printf("Enter How Many Array Elements Do You Want:: ");
    scanf("%d", &size);

    int a[size];

    for (i = 0; i < size; i++)
    {
        printf("Enter Element %d: ", (i + 1));
        scanf("%d", &a[i]);
    }

    while (1)
    {
        system("cls");

        printf("============= Select Serching Technique =============");
        printf("\n1. Linear Search \n2. Binary Search \n0. Exit");
        printf("\nEnter Your Choice:: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
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
            getch();
            break;

        case 2:
            printf("Enter Which Element Do You Find: ");
            scanf("%d", &key);

            ans = binary_search(a, 0, size, key);

            if (ans == -1)
            {
                printf("Element Not Fount.!");
            }
            else
            {
                printf("Element is Found at %d", ans);
            }
            getch();
            break;

        case 0:
            exit(0);

        default:
            break;
        }
    }
}