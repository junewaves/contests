#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<bool> vis(n), forbid(n);
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto dfs = [&](auto dfs_, int u) -> void {
            vis[u] = true;
            if (!forbid[u]) {
                forbid[u] = true;
                ans.push_back(u + 1);
                for (int v : adj[u])
                    forbid[v] = true;
            }
            for (int v : adj[u])
                if (!vis[v])
                    dfs_(dfs_, v);
        };
        dfs(dfs, 0);
        if (find(vis.begin(), vis.end(), false) != vis.end()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (int t : ans)
                cout << t << ' ';
            cout << '\n';
        }
    }
    return 0;
}