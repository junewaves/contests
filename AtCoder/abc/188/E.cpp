#include <bits/stdc++.h>
using namespace std;

constexpr int mxn = 2e5 + 5, inf = 2e9 + 7;
int n, m, a[mxn], b[mxn];
vector<int> adj[mxn];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = inf;
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = -inf;
    for (int u = 1; u <= n; u++) {
        ans = max(ans, a[u] - b[u]);
        b[u] = min(a[u], b[u]);
        for (int v : adj[u])
            b[v] = min(b[v], b[u]);
    }
    cout << ans << '\n';
    return 0;
}