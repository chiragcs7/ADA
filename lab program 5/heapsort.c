#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void heapcom(int a[], int n)
{
    int i, j, k, item;

    for(i=1; i<=n; i++)
    {
        item = a[i];
        j = i;
        k = j/2;

        while(k!=0 && item>a[k])
        {
            a[j] = a[k];
            j = k;
            k = j/2;
        }

        a[j] = item;
    }
}

void adjust(int a[], int n)
{
    int item, i, j;

    j = 1;
    item = a[j];
    i = 2*j;

    while(i < n)
    {
        if((i+1) < n)
        {
            if(a[i] < a[i+1])
                i++;
        }

        if(item < a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2*j;
        }
        else
            break;
    }

    a[j] = item;
}

void heapsort(int a[], int n)
{
    int i, temp;

    heapcom(a, n);

    for(i=n; i>=1; i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        adjust(a, i);
    }
}

int main()
{
    int i, n;
    int a[100000];

    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(0));

 
    for(i=1; i<=n; i++)
    {
        a[i] = rand() % 1000;
    }

    printf("\nRandom elements are:\n");

    for(i=1; i<=n; i++)
    {
        printf("%d ", a[i]);
    }

    start = clock();

    heapsort(a, n);

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nSorted elements are:\n");

    for(i=1; i<=n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nTime taken = %lf seconds\n", cpu_time);

    return 0;
}
