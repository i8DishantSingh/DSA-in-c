#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSortIterative(int arr[], int low, int high)
{
    // auxillary stack
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        int pi = partition(arr, low, high);

        if (pi - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high)
        {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    quickSortIterative(arr, 0, size - 1);

    printf("\nSorted array:\n");
    printArray(arr, size);

    return 0;
}