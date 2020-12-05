#include <bits/stdc++.h>
using namespace std;

constexpr int mxn = 2e5 + 5;
int ans;
vector<int> adj[mxn];

int dfs(int u, int p) {
    int mx = -1, mx2 = -1, mn = mxn;
    for (int v : adj[u]) {
        if (v == p) continue;
        int d = dfs(v, u);
        mn = min(mn, d);
        mx2 = d > mx ? exchange(mx, d) : max(d, mx2);
    }
    if (mx == -1)
        return 1;
    if (u == 0)
        ans = max({ans, mx, mx2 + 1});
    else
        ans = max(ans, mx + 1);
    return mn + 1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        adj[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 1;
    dfs(0, -1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt; 
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}