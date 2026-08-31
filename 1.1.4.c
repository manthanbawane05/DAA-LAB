#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void kruskalMST(int **cost, int V) {
    // Structure to represent an edge
    struct Edge {
        int u, v, weight;
    };

    struct Edge edges[10000];
    int edgeCount = 0;

    // 1. Collect edges from the upper triangular matrix (i < j)
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (cost[i][j] != 9999) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = cost[i][j];
                edgeCount++;
            }
        }
    }

    // 2. Stable sort (Bubble Sort) to preserve row-wise order for equal weights
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // 3. Initialize Union-Find parent array
    int parent[100];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    int edgeIndex = 0;

    // 4. Kruskal's algorithm
    for (int i = 0; i < edgeCount && edgeIndex < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Find root of u directly
        int rootU = u;
        while (parent[rootU] != rootU) {
            rootU = parent[rootU];
        }

        // Find root of v directly
        int rootV = v;
        while (parent[rootV] != rootV) {
            rootV = parent[rootV];
        }

        // Include edge if it does not create a cycle
        if (rootU != rootV) {
            printf("Edge %d:(%d, %d) cost:%d\n", edgeIndex++, u, v, weight);
            totalCost += weight;
            parent[rootU] = rootV; // Union
        }
    }

    // 5. Print final total cost
    printf("Minimum cost= %d\n", totalCost);
}



int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
