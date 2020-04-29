#include <stdio.h>

int dp[31][31];

int recur(int n, int m) {
    if (m == 0 || m == n)
        return 1;
    if (dp[n - 1][m - 1] == 0)
        dp[n - 1][m - 1] = recur(n - 1, m - 1);
    if (dp[n - 1][m] == 0)
        dp[n - 1][m] = recur(n - 1, m);
    return dp[n - 1][m - 1] + dp[n - 1][m];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", recur(n, m));
}
