#include <stdio.h>
#include <stdlib.h>

void dfs(int **adj, int *visited, int nodes, int start)
{
    int *stack = (int *)malloc(nodes * sizeof(int));
    int top = -1, i;

    for (i = 0; i < nodes; i++)
    {
        visited[i] = 0;
    }
    stack[++top] = start;
    visited[start] = 1;

    while (top != -1)
    {
        start = stack[top--];
        printf("%d->", start);

        for (i = 0; i < nodes; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    free(stack);
}

int main()
{
    int nodes, i, j;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodes);

    int **adj = (int **)malloc(nodes * sizeof(int *));
    for (i = 0; i < nodes; i++)
    {
        adj[i] = (int *)malloc(nodes * sizeof(int));
    }

    int *visited = (int *)malloc(nodes * sizeof(int));

    printf("\nEnter the adjacency matrix (size %dx%d):\n", nodes, nodes);
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("DFS Traversal: ");
    dfs(adj, visited, nodes, 0);

    for (i = 0; i < nodes; i++)
    {
        free(adj[i]);
    }
    free(adj);
    free(visited);

    return 0;
}
