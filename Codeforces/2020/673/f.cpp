#include <bits/stdc++.h>
using namespace std;

int n, m, q, timer, real_n;
vector<int> a, g, ts, te;
vector<vector<int>> adj;
vector<pair<int, int>> segtree;
int get(int u) {
    return u == g[u] ? u : g[u] = get(g[u]);
}
void uni(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return;
    adj.push_back({u, v});
    g.push_back(n);
    g[u] = n;
    g[v] = n;
    n++;
}
void dfs(int u) {
    segtree.emplace_back(u < real_n ? a[u] : 0, timer);
    ts[u] = timer++;
    for (int v : adj[u]) {
        dfs(v);
    }
    te[u] = timer;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> q;
    real_n = n;
    a.resize(n);
    for (auto& it : a)  
        cin >> it;
    vector<array<int, 2>> edges(m);
    for (auto& it : edges) {
        cin >> it[0] >> it[1];
        --it[0], --it[1];
    }
    vector<array<int, 2>> queries(q);
    vector<int> erased(m);
    for (auto& it : queries) {
        cin >> it[0] >> it[1];
        --it[1];
        if (it[0] == 2) {
            erased[it[1]] = true;
        }
    }
    g.resize(n);
    g.reserve(n * 2);
    adj.resize(n);
    adj.reserve(n * 2);
    iota(g.begin(), g.end(), 0);
    for (int i = 0; i < m; i++) {
        if (!erased[i]) {
            uni(edges[i][0], edges[i][1]);
        }
    }
    vector<int> real_queries;
    for (int i = q - 1; i >= 0; i--) {
        if (queries[i][0] == 1) {
            real_queries.push_back(get(queries[i][1]));
        } else {
            auto& e = edges[queries[i][1]];
            uni(e[0], e[1]);
        }
    }
    ts.resize(n, -1);
    te.resize(n, -1);
    segtree.resize(n, {0, -1});
    segtree.reserve(n * 2);
    for (int i = 0; i < real_n; i++) {
        int leader = get(i);
        if (ts[leader] == -1) {
            dfs(leader);
        }
    }
    for (int i = n - 1; i > 0; i--) {
        segtree[i] = max(segtree[i << 1], segtree[i << 1 | 1]);
    }
    reverse(real_queries.begin(), real_queries.end());
    for (int qi : real_queries) {
        pair<int, int> res = {0, -1};
        for (int l = ts[qi] + n, r = te[qi] + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, segtree[l++]);
            if (r & 1) res = max(res, segtree[--r]);
        }
        cout << res.first << '\n';
        if (res.first != 0) {
            int i = res.second + n;
            segtree[i].first = 0;
            for (; i >>= 1;) {
                segtree[i] = max(segtree[i << 1], segtree[i << 1 | 1]);
            }
        }
    }
    return 0;
}