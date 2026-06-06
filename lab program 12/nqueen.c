#include<stdio.h>
#include<stdlib.h>

int x[20], count = 0;

int place(int k, int i)
{
    int j;
    for(j = 1; j < k; j++)
    {
        if((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }
    return 1;
}

void nqueen(int k, int n)
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                count++;

                printf("\nSolution %d:\n\n", count);

                for(i = 1; i <= n; i++)
                {
                    for(j = 1; j <= n; j++)
                    {
                        if(x[i] == j)
                            printf(" Q ");
                        else
                            printf(" . ");
                    }
                    printf("\n");
                }
            }
            else
            {
                nqueen(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    nqueen(1, n);

    if(count == 0)
        printf("\nNo solution exists");

    return 0;
}
