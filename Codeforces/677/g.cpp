#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int INF = 1e9 + 5;
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> edges(m), query(k);
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        edges[i] = {u, v};
    }
    for (int i = 0; i < k; i++) {
        cin >> query[i].first >> query[i].second;
    }
    for (int x = 1; x <= n; x++) {
        dis[x][x] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, x);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dis[x][u]) continue;
            for (auto [v, w] : adj[u]) {
                if ((w += d) < dis[x][v]) {
                    dis[x][v] = w;
                    pq.emplace(w, v);
                }
            }
        }
    }
    int ans = INF;
    for (auto [u, v] : edges) {
        int cost = 0;
        for (auto [a, b] : query) {
            cost += min({dis[a][b], dis[a][u] + dis[v][b], dis[a][v] + dis[u][b]});
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}