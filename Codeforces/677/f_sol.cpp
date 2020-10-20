#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(k, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        vector<vector<int>> tmp(k, vector<int>(m / 2 + 1, -1));
        tmp[0][0] = 0;
        for (int j = 0; j < m; j++) {
            for (int y = m / 2 - 1; y >= 0; y--) {
                for (int x = 0; x < k; x++) {
                    if (tmp[x][y] >= 0) {
                        int nxt = tmp[x][y] + a[i][j];
                        tmp[nxt % k][y + 1] = max(tmp[nxt % k][y + 1], nxt);
                    }
                }
            }
        }
        for (int x = 0; x < k; x++) {
            for (int y = 0; y <= m / 2; y++) {
                dp[i][x] = max(dp[i][x], tmp[x][y]);
            }
        }
    }
    vector<int> ndp = dp[0];
    for (int row = 1; row < n; row++) {
        for (int i = 0; i < k; i++) {
            if (dp[row][i] < 0) continue;
            for (int j = 0; j < k; j++) {
                if (dp[row - 1][j] < 0) continue;
                int col = (i + j) % k;
                ndp[col] = max(ndp[col], dp[row][i] + dp[row - 1][j]);
            }
        }
        dp[row] = ndp;
    }
    cout << ndp[0];
    return 0;
}