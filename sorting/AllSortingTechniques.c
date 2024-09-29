#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// =============== BUBBLE SORT ===============

void bubbleSort(int a[], int size)
{
    int i, j, temp;
    for (i = 1; i < size - 1; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// =============== INSERTION SORT ===============

void insertionSort(int a[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = a[i];
        j = i;
        while ((j > 0 && (a[j - 1] > key)))
        {
            a[j] = a[j - 1];
            j -= 1;
        }
        a[j] = key;
    }
}

// =============== HEAP SORT ===============

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int size, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if ((left < size) && (a[left] > a[largest]))
        largest = left;
    if ((right < size) && (a[right] > a[largest]))
        largest = right;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, size, largest);
    }
}

void heapSort(int a[], int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(a, size, i);
    }

    for (i = size - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

// =============== SELECTION SORT ===============

void selectionSort(int a[], int size)
{
    int minIndex, minValue;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        minValue = a[i];
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < minValue)
            {
                minIndex = j;
                minValue = a[j];
            }
        }
        if (minIndex != i)
        {
            a[minIndex] = a[i];
            a[i] = minValue;
        }
    }
}

// =============== MERGE SORT ===============

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int leftArray[n1], rightArray[n2];

    // copy array element into left array from main array
    for (i = 0; i < n1; i++)
    {
        leftArray[i] = a[low + i];
    }

    // copy array element into right array from main array
    for (j = 0; j < n2; j++)
    {
        rightArray[j] = a[mid + 1 + j];
    }

    i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            a[k] = leftArray[i];
            i++;
        }
        else
        {
            a[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid;
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

// =============== QUICK SORT ===============

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[lb], &a[end]);
    return end;
}

void quickSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(a, lb, ub);
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}

// =============== NEW ARRAY ===============

void newArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Enter Element %d: ", (i + 1));
        scanf("%d", &a[i]);
    }
}

// =============== PRINT ARRAY ===============

void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
}

void main()
{

    int size, i, choice;

    printf("Enter How Many Array Elements Do You Want:: ");
    scanf("%d", &size);

    int a[size];

    while (1)
    {
        system("cls");

        printf("============= Select Sorting Technique =============");
        printf("\n1. Bubble Sort \n2. Insertion Sort \n3. Heap Sort\n4. Selection Sort\n5. Merge Sort \n6. Quick Sort \n0. Exit");
        printf("\nEnter Your Choice:: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            newArray(a, size);
            printf("\n========== Bubble Sort ==========\n");
            printf("\n========== Print Array Before Sorting ==========\n");
            printArray(a, size);
            bubbleSort(a, size);
            printf("\n========== Print Array After Sorting ==========\n");
            printArray(a, size);
            getch();
            break;

        case 2:
            newArray(a, size);
            printf("\n========== Insertion Sort ==========\n");
            printf("\n========== Print Array Before Sorting ==========\n");
            printArray(a, size);
            insertionSort(a, size);
            printf("\n========== Print Array After Sorting ==========\n");
            printArray(a, size);
            getch();
            break;

        case 3:
            newArray(a, size);
            printf("\n========== Heap Sort ==========\n");
            printf("\n========== Print Array Before Sorting ==========\n");
            printArray(a, size);
            heapSort(a, size);
            printf("\n========== Print Array After Sorting ==========\n");
            printArray(a, size);
            getch();
            break;

        case 4:
            newArray(a, size);
            printf("\n========== Selection Sort ==========\n");
            printf("\n========== Print Array Before Sorting ==========\n");
            printArray(a, size);
            selectionSort(a, size);
            printf("\n========== Print Array After Sorting ==========\n");
            printArray(a, size);
            getch();
            break;

        case 5:
            newArray(a, size);
            printf("\n========== Merge Sort ==========\n");
            printf("\n========== Print Array Before Sorting ==========\n");
            printArray(a, size);
            mergeSort(a, 0, size - 1);
            printf("\n========== Print Array After Sorting ==========\n");
            printArray(a, size);
            getch();
            break;

        case 6:
            newArray(a, size);
            printf("\n========== Quick Sort ==========\n");
            printf("\n========== Print Array Before Sorting ==========\n");
            printArray(a, size);
            quickSort(a, 0, size - 1);
            printf("\n========== Print Array After Sorting ==========\n");
            printArray(a, size);
            getch();
            break;

        case 0:
            exit(0);

        default:
            break;
        }
    }
}
