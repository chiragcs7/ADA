#include <stdio.h>

int main()
{
    int n;
    int adj[20][20];
    int indegree[20] = {0};
    int visited[20] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    printf("Topological Sorting Order:\n");

    for (int count = 0; count < n; count++)
    {
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0 && visited[i] == 0)
            {
                printf("%d ", i);
                visited[i] = 1;

                for (int j = 0; j < n; j++)
                {
                    if (adj[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }
            }
        }
    }

    return 0;
}
