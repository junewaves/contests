#include <stdio.h>

// int dp[4][11];
/*int A(int n, int m) {
    if (n == 0)
        return m + 1;
    if (m == 0)
        return A(n - 1, 1);
    return A(n - 1, A(n, m - 1));
}*/
// from wikipedia
int A(int n, int m) {
    if (n == 2)
        return (m << 1) + 3;
    else if (n == 3)
        return (1 << (m + 3)) - 3;
    else
        return n + m + 1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", A(n, m));
}
