#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9 + 5;
int n, m;
vector<vector<pair<int, int>>> adj;

int dijkstra(int s) {
    vector<int> dis(n, inf);
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(s, 0);
    int comeback = inf;
    while (pq.size()) {
        auto [u, w] = pq.top();
        pq.pop();
        if (w > dis[u]) continue;
        for (auto [v, d] : adj[u]) {
            if (v == s) {
                comeback = min(comeback, w + d);
            } else if (dis[v] > w + d) {
                dis[v] = w + d;
                pq.emplace(v, w + d);
            }
        }
    }
    return comeback < inf ? comeback : -1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        adj[u].emplace_back(v, c);
    }
    for (int i = 0; i < n; i++)
        cout << dijkstra(i) << '\n';
    return 0;
}
