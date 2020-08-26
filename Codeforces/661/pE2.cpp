#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...)
#endif

constexpr int mxn = 2e5;
vector<pair<int, int>> adj[mxn];
vector<ll> dp[2];
int cnt[mxn], weight[mxn], cost[mxn];
ll sum[2];
int dfs(int u = 0, int id = -1, int p = -1) {
    int lf = 0;
    for (auto [v, i] : adj[u]) {
        if (v != p) {
            lf += dfs(v, i, u);
        }
    }
    lf += (lf == 0);
    if (id != -1) {
        cnt[id] = lf;
        sum[cost[id] - 1] += (ll)cnt[id] * weight[id];
    }
    return lf;
}

// int search(int c, ll v) {
//     int l = 0, r = dp[c].size(), m;
//     while (l < r) {
//         m = (l + r) / 2;
//         if (dp[c][m] > v)
//             l = m + 1;
//         else
//             r = m;
//     }
//     return l;
// }
void solve() {
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        adj[i].clear();
    memset(cnt, 0, 4 * n);
    memset(weight, 0, 4 * n);
    vector<int> edge[2];
    for (int i = 0; i < n - 1; i++) {
        int u, v, w, c;
        cin >> u >> v >> w >> c, --u, --v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        weight[i] = w;
        cost[i] = c;
        edge[c - 1].push_back(i);
    }
    sum[0] = sum[1] = 0;
    dfs();
    dp[0].clear();
    dp[1].clear();
    for (int c : {0, 1}) {
        priority_queue<pair<ll, int>> q;
        for (int i : edge[c])
            q.emplace((ll)cnt[i] * ((weight[i] + 1) / 2), i);
        dp[c].push_back(sum[c]);
        while (sum[c] > 0) {
            auto [w, i] = q.top();
            q.pop();
            weight[i] /= 2;
            sum[c] -= w;
            q.emplace((ll)cnt[i] * ((weight[i] + 1) / 2), i);
            dp[c].push_back(sum[c]);
        }
    }
    int ans = 1e9;
    // for (int i = search(0, m); i < (int)dp[0].size(); i++)
    //     ans = min(ans, i + 2 * search(1, m - dp[0][i]));
    // int i = lower_bound(dp[0].begin(), dp[0].end(), m, greater<ll>()) -
    //         dp[0].begin(),
    //     j = dp[1].size() - 1;
    for (int i = lower_bound(dp[0].begin(), dp[0].end(), m, greater<ll>()) -
                 dp[0].begin(),
             j = dp[1].size() - 1;
         i < (int)dp[0].size(); i++) {
        while (j >= 0 && dp[0][i] + dp[1][j] <= m)
            j--;
        ans = min(ans, i + 2 * (j + 1));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}