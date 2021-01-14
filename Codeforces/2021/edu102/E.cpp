#include <bits/stdc++.h>
using namespace std;

template <class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    auto decode = [](int x) -> tuple<int, int, int> {
        int a = x & 1;
        x >>= 1;
        int b = x & 1;
        x >>= 1;
        return {x, a, b};
    };
    auto encode = [](int x, int a, int b) -> int {
        x <<= 2;
        x |= 1 * a;
        x |= 2 * b;
        return x;
    };
    vector<int64_t> dist[2][2];
    for (int i : {0, 1})
        for (int j : {0, 1})
            dist[i][j].resize(n, 1e18);
    dist[0][0][0] = 0;
    min_pq<pair<int64_t, int>> pq;
    pq.emplace(0, 0);
    while (pq.size()) {
        auto [cur, x] = pq.top();
        auto [u, a, b] = decode(x);
        pq.pop();
        if (cur != dist[a][b][u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[a][b][v] > cur + w) {
                dist[a][b][v] = cur + w;
                pq.emplace(dist[a][b][v], encode(v, a, b));
            }
            if (a == 0 && dist[1][b][v] > cur) {
                dist[1][b][v] = cur;
                pq.emplace(dist[1][b][v], encode(v, 1, b));
            }
            if (b == 0 && dist[a][1][v] > cur + w + w) {
                dist[a][1][v] = cur + w + w;
                pq.emplace(dist[a][1][v], encode(v, a, 1));
            }
            // if (a == 0 && b == 0 && dist[1][1][v] > cur + w) {
            //     dist[1][1][v] = cur + w;
            //     pq.emplace(dist[1][1][v], encode(v, 1, 1));
            // }
        }
    }
    for (int i = 1; i < n; i++) 
        cout << min(dist[0][0][i], dist[1][1][i]) << " \n"[i == n - 1];
    return 0;
}
