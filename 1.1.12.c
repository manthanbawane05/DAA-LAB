#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LENGTH 100

int max(int a, int b){if(a>b){return a;}else{return b;}}

int lcsOf3(char X[], char Y[], char Z[], int m, int n, int o){
	
	//write your code here...
		
	// Strip trailing newline characters from fgets if they exist
	if (m > 0 && X[m - 1] == '\n') m--;
	if (n > 0 && Y[n - 1] == '\n') n--;
	if (o > 0 && Z[o - 1] == '\n') o--;

	// 3D DP array to store the length of LCS
	int dp[m + 1][n + 1][o + 1];

	// Build the DP table in a bottom-up manner
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= o; k++) {
				if (i == 0 || j == 0 || k == 0) {
					dp[i][j][k] = 0;
				} else if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				} else {
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
				}
			}
		}
	}

	// The last cell contains the maximum LCS length
	return dp[m][n][o];
	
	
	
	
	
	
}

int main()
{	char x[MAX_LENGTH], y[MAX_LENGTH],z[MAX_LENGTH];
    fgets(x, MAX_LENGTH, stdin);
    fgets(y, MAX_LENGTH, stdin);
    fgets(z, MAX_LENGTH, stdin);
	printf("%d", lcsOf3(x, y, z, strlen(x), strlen(y), strlen(z)));
	
	return 0;
}
