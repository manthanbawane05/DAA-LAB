#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX


typedef struct {
	int u;
	int v;
	int w;
} Edge;

void printPath(int parent[], int vertex) {
	if (parent[vertex] == -1) {
		printf("%d", vertex);
		return;
	}
	printPath(parent, parent[vertex]);
	printf("->%d", vertex);
}

int main() {
	int V, E;
	if (scanf("%d", &V) != 1) return 0;
	if (scanf("%d", &E) != 1) return 0;

	Edge* edges = (Edge*)malloc(E * sizeof(Edge));
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	}

	int source;
	scanf("%d", &source);

	long long* dist = (long long*)malloc((V + 1) * sizeof(long long));
	int* parent = (int*)malloc((V + 1) * sizeof(int));

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
		parent[i] = -1;
	}
	dist[source] = 0;

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = edges[j].u;
			int v = edges[j].v;
			int w = edges[j].w;

			if (dist[u] != INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				parent[v] = u;
			}
		}
	}

	int has_negative_cycle = 0;
	for (int j = 0; j < E; j++) {
		int u = edges[j].u;
		int v = edges[j].v;
		int w = edges[j].w;

		if (dist[u] != INF && dist[u] + w < dist[v]) {
			has_negative_cycle = 1;
			break;
		}
	}

	if (has_negative_cycle) {
		printf("Negative cycle detected\n");
	} else {
		for (int i = 1; i <= V; i++) {
			if (i == source) {
				continue;
			}
			if (dist[i] == INF) {
				printf("%d INF None\n", i);
			} else {
				printf("%d %lld ", i, dist[i]);
				printPath(parent, i);
				printf("\n");
			}
		}
	}

	free(edges);
	free(dist);
	free(parent);

	return 0;
}

