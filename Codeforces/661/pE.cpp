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
vector<int> cnt, weight;
ll sum;
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
        sum += (ll)cnt[id] * weight[id];
    }
    return lf;
}
void solve() {
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        adj[i].clear();
    weight.resize(n - 1);
    fill(weight.begin(), weight.end(), 0);
    cnt.resize(n - 1);
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        weight[i] = w;
    }
    sum = 0;
    dfs();
    priority_queue<pair<ll, int>> q;
    for (int i = 0; i < n - 1; i++)
        q.emplace((ll)cnt[i] * ((weight[i] + 1) / 2), i);
    int ans = 0;
    while (sum > m) {
        auto [w, i] = q.top();
        q.pop();
        weight[i] /= 2;
        sum -= w;
        q.emplace((ll)cnt[i] * ((weight[i] + 1) / 2), i);
        ans++;
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