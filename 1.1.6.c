#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
int distance[MAX], visited[MAX], parent[MAX];
int i, j, min, next;
int path[MAX], count, current;

/* Initialize */
for (i = 1; i <= n; i++) {
distance[i] = INFINITY;
visited[i] = 0;
parent[i] = -1;
}

distance[startnode] = 0;

/* Dijkstra */
for (i = 1; i <= n; i++) {
min = INFINITY;
next = -1;

for (j = 1; j <= n; j++) {
if (!visited[j] && distance[j] < min) {
min = distance[j];
next = j;
}
}

if (next == -1)
break;

visited[next] = 1;

for (j = 1; j <= n; j++) {
if (j != next && G[next][j] != 0) {
if (distance[next] + G[next][j] < distance[j]) {
distance[j] = distance[next] + G[next][j];
parent[j] = next;
}
}
}
}

/* Output */
printf("Node\tDistance\tPath\n");

for (i = 1; i <= n; i++) {

/* Do not print source vertex */
if (i == startnode)
continue;

printf("%4d\t", i);

/* Unreachable vertex */
if (distance[i] == INFINITY) {
printf("     INF\tNO PATH\n");
}
else {
printf("%8d\t", distance[i]);

/* Build path: destination -> source */
current = i;
count = 0;

while (current != -1) {
path[count++] = current;
current = parent[current];
}
for (j = 0; j < count; j++) {
printf("%d", path[j]);

if (j < count - 1)
printf("<-");
}

printf("\n");
}
}
	// write your code here
	
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
} 
