#include <stdio.h>

int main() {
	int n, capacity;

	scanf("%d", &n);

	int value[n], weight[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &value[i]);

	for (int i = 0; i < n; i++)
		scanf("%d", &weight[i]);

	scanf("%d", &capacity);

	int dp[capacity + 1];

	for (int i = 0; i <= capacity; i++)
		dp[i] = 0;

	for (int i = 0; i < n; i++) {
		for (int w = capacity; w >= weight[i]; w--) {
			if (dp[w - weight[i]] + value[i] > dp[w])
				dp[w] = dp[w - weight[i]] + value[i];
		}
	}

	printf("%d", dp[capacity]);

	return 0;
}
