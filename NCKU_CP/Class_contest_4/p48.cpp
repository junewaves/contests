#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n == m) {
        cout << "1\n";
        exit(0);
    } else if (n == 1) {
        cout << m << '\n';
        exit(0);
    } else if (m == 1) {
        cout << n << '\n';
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j)
                dp[i][j] = 1;
            else if (i == 1 || j == 1)
                dp[i][j] = max(i, j);
            else {
                int best = 1e9;
                for (int x = 1; x <= i && j - x > 0; x++) {
                    best = min(best, dp[i][x] + dp[i][j - x]);
                }
                for (int y = 1; y <= j && i - y > 0; y++) {
                    best = min(best, dp[y][j] + dp[i - y][j]);
                }
                dp[i][j] = best;
            }
        }
    }
    cout << dp[n][m] << '\n';
}
