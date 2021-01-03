#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(n));
    vector<int> dp(1 << n, 0);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        --u, --v;
        a[u][v] = a[v][u] = true;
    }
    dp[0] = 0;
    auto is_clique = [&](int mask) -> bool {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < n; j++) {
                if (i == j || !(mask & (1 << j))) continue;
                if (!a[i][j]) return false;
            }
        }
        return true;
    };
    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == 1 || is_clique(mask)) {
            dp[mask] = 1;
            continue;
        }
        dp[mask] = int(1e9);
        for (int sub = mask; sub; sub = (sub - 1) & mask) {
            dp[mask] = min(dp[mask], dp[sub] + dp[mask ^ sub]);
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}
