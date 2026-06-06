#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    float ratio;
};

void sortItems(struct Item item[], int n)
{
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    float capacity, totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d%d", &item[i].profit, &item[i].weight);

        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    sortItems(item, n);

    for(i = 0; i < n; i++)
    {
        if(capacity >= item[i].weight)
        {
            capacity = capacity - item[i].weight;
            totalProfit = totalProfit + item[i].profit;
        }
        else
        {
            totalProfit = totalProfit + (item[i].ratio * capacity);
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}
