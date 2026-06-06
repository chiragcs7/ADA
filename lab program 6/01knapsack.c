#include<stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, W;
    int wt[10], val[10];
    int V[10][10];
    int i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for(i=1; i<=n; i++)
        scanf("%d", &wt[i]);

    printf("Enter profits:\n");
    for(i=1; i<=n; i++)
        scanf("%d", &val[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

   
    for(i=0; i<=n; i++)
    {                     
        for(j=0; j<=W; j++)
        {
            if(i==0 || j==0)
            {
                V[i][j] = 0;
            }
            else if(wt[i] > j)
            {
                V[i][j] = V[i-1][j];
            }
            else
            {
                V[i][j] = max(V[i-1][j],
                              V[i-1][j-wt[i]] + val[i]);
            }
        }
    }

    printf("\nDP Table:\n\n");

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=W; j++)
        {
            printf("%4d", V[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", V[n][W]);

    return 0;
}
