#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

int n;
int cost[20][20];
int memo[20][1 << 20];


int min(int a, int b) {
    return (a < b) ? a : b;
}


int tsp(int u, int mask) {

    if (mask == (1 << n) - 1) {

        return (cost[u][0] != -1) ? cost[u][0] : INF;
    }
    

    if (memo[u][mask] != -1) {
        return memo[u][mask];
    }
    
    int ans = INF;
    

    for (int v = 0; v < n; v++) {

        if (!(mask & (1 << v)) && cost[u][v] != -1) {
            int new_cost = cost[u][v] + tsp(v, mask | (1 << v));
            ans = min(ans, new_cost);
        }
    }
    
    return memo[u][mask] = ans;
}

int main() {

    if (scanf("%d", &n) != 1) return 0;
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            memo[i][j] = -1;
        }
    }
    

    int result = tsp(0, 1);
    

    printf("%d\n", result);
    
    return 0;
}

