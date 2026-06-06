#include <stdio.h>

#define LEFT -1
#define RIGHT 1

int getMobile(int a[], int dir[], int n)
{
    int mobile = 0;
    int mobile_index = -1;

    for (int i = 0; i < n; i++)
    {
        
        if (dir[a[i]] == LEFT && i != 0)
        {
            if (a[i] > a[i - 1] && a[i] > mobile)
            {
                mobile = a[i];
                mobile_index = i;
            }
        }


        if (dir[a[i]] == RIGHT && i != n - 1)
        {
            if (a[i] > a[i + 1] && a[i] > mobile)
            {
                mobile = a[i];
                mobile_index = i;
            }
        }
    }

    return mobile_index;
}


void printPermutation(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


void johnsonTrotter(int n)
{
    int a[20], dir[21];

  
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i + 1] = LEFT;
    }


    printPermutation(a, n);

    while (1)
    {
        int mobile_index = getMobile(a, dir, n);


        if (mobile_index == -1)
            break;

        int mobile = a[mobile_index];

       
        if (dir[mobile] == LEFT)
        {
            int temp = a[mobile_index];
            a[mobile_index] = a[mobile_index - 1];
            a[mobile_index - 1] = temp;

            mobile_index--;
        }
        else
        {
            int temp = a[mobile_index];
            a[mobile_index] = a[mobile_index + 1];
            a[mobile_index + 1] = temp;

            mobile_index++;
        }

 
        for (int i = 1; i <= n; i++)
        {
            if (i > mobile)
                dir[i] = -dir[i];
        }


        printPermutation(a, n);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
