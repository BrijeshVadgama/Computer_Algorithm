#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, minCost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);

int main()
{
    printf("\n\tImplementation of Kruskal's algorithm\n");
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        parent[i] = 0;
    }

    printf("The edges of minimum cost spanning tree are:\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            printf("\nEdge %d:(%d, %d) cost = %d", ne++, a, b, min);
            minCost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", minCost);

    return 0;
}

int find(int i)
{
    while (parent[i])
    {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j)
{
    int x = find(i);
    int y = find(j);
    if (x != y)
    {
        parent[x] = y;
        return 1;
    }
    return 0;
}

/*
            Implementation of Kruskal's algorithm

Enter the number of vertices: 6
Enter the cost adjacency matrix:
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
The edges of minimum cost spanning tree are:

Edge 1:(1, 3) cost = 1
Edge 2:(4, 6) cost = 2
Edge 3:(1, 2) cost = 3
Edge 4:(2, 5) cost = 3
Edge 5:(3, 6) cost = 4
Minimum cost = 13
 */


