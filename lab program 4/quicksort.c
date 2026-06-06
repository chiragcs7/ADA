#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1, j, temp;

    for(j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(0));   // Random seed

    printf("Generated array:\n");
    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }

    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();

    cpu_time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

    printf("\n\nSorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nTime taken = %f ms\n", cpu_time);

    return 0;
}
