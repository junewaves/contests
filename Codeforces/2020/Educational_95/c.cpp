#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<array<int, 2>> dp(n + 2, {INT_MAX, INT_MAX});
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[n] = dp[n + 1] = array<int, 2>{0, 0};
    for (int i = n - 1; i >= 0; i--) {
        int cost1 = a[i];
        int cost2 = a[i] + a[i + 1];
        for (int p : {0, 1}) {
            dp[i][p] = min(dp[i][p], cost1 * p + dp[i + 1][p ^ 1]);
            dp[i][p] = min(dp[i][p], cost2 * p + dp[i + 2][p ^ 1]);
        }
    }
    cout << dp[0][1] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}