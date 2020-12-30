#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

constexpr int mxn = 5e5 + 10;
vector<int> adj[mxn], dep[mxn];
bool vis[mxn];
int n, m, pairs;
bool dfs(int u = 1, int d = 1) {
    vis[u] = true;
    if (d >= (n + 1) / 2) {
        cout << "PATH\n" << d << '\n' << u << ' ';
        return true;
    }
    if (dep[d].size() & 1) pairs++;
    dep[d].push_back(u);
    for (int v : adj[u]) {
        if (!vis[v] && dfs(v, d + 1)) {
            cout << u << ' ';
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n >> m;
    pairs = 0;
    memset(vis, 0, n);
    for (int i = 1; i <= n; i++)
        adj[i].clear(), dep[i].clear();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (dfs()) {
        cout << '\n';
        return;
    }
    cout << "PAIRING\n";
    cout << pairs << '\n';
    for (int d = 1; d <= n / 2; d++)
        for (int i = 0; i + 1 < (int)dep[d].size(); i += 2)
            cout << dep[d][i] << ' ' << dep[d][i + 1] << '\n';
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