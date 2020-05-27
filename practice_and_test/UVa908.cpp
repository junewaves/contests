#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id, w;
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const { return w > o.w; }  // make min heap
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, cases = 0;
    while (cin >> n) {
        int u, v, w, old = 0;
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v >> w;
            old += w;
        }
        vector<vector<Node>> adj(n);
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> u >> v >> w;
            --u, --v;
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
        cin >> m;
        for (int i = k; i < k + m; i++) {
            cin >> u >> v >> w;
            --u, --v;
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
        priority_queue<Edge> q;
        vector<bool> vis(n);
        q.push({ 0, 0, 0 });
        int ans = 0;
        while (!q.empty()) {
            Edge e = q.top();
            q.pop();
            if (vis[e.v])
                continue;
            vis[e.v] = true;
            ans += e.w;
            for (const auto& nxt : adj[e.v])
                if (!vis[nxt.id])
                    q.push({ e.v, nxt.id, nxt.w });
        }
        if (cases++)
            cout << '\n';
        cout << old << '\n' << ans << '\n';
    }
}
