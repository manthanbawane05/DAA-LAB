#include <stdio.h>
for (int i = 0; i < V; i++) {
    for (p = adjList[i]; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->vertex > q->vertex) {
                temp = p->vertex;
                p->vertex = q->vertex;
                q->vertex = temp;
            }
        }
    }
}
    
    
    
}

// Depth-First Search (DFS) function
void DFS(int start) {
    //write your code here...
    Node* p;

visited[start] = 1;
printf("%d ", start);

p = adjList[start];

while (p != NULL) {
    if (visited[p->vertex] == 0) {
        DFS(p->vertex);
    }
    p = p->next;
}

    
    
    
}

int main() {
    int V, E;
    int u, v, start;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Read the edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort the adjacency list for each vertex
    sortAdjList(V);

    // Read the starting node
    scanf("%d", &start);

    // Perform DFS starting from the given node
    DFS(start);

    return 0;
}
