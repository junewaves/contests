#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
constexpr ll INF = 1e18;
ll t, n, m;
vector<vector<ll>> a, dp;
ll run_dp(ll b) {
    if (a[0][0] < b)
        return INF;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((a[i][j] < b + i + j) || (i == 0 && j == 0))
                continue;
            ll s = INF;
            if (i)
                s = min(s, dp[i - 1][j]);
            if (j)
                s = min(s, dp[i][j - 1]);
            dp[i][j] = s + a[i][j] - (b + i + j);
        }
    }
    return dp[n - 1][m - 1] + a[0][0] - b;
}
void solve() {
    cin >> n >> m;
    a.assign(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp.assign(n, vector<ll>(m, INF));
            ans = min(ans, run_dp(a[i][j] - i - j));
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
}

