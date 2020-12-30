#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            int w = a[i][j];
            int x = a[i][m - 1 - j];
            int y = a[n - 1 - i][j];
            int z = a[n - 1 - i][m - 1 - j];
            int64_t min_cost = LLONG_MAX;
            for (int u : {w, x, y, z}) {
                int64_t cost = 0;
                for (int v : {w, x, y, z}) {
                    cost += abs(u - v);
                }
                min_cost = min(min_cost, cost);
            }
            ans += min_cost;
        }
        if (m & 1) {
            ans += abs(a[i][m / 2] - a[n - 1 - i][m / 2]);
        }
    }
    if (n & 1) {
        for (int j = 0; j < m / 2; j++) {
            ans += abs(a[n / 2][j] - a[n / 2][m - 1 - j]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}