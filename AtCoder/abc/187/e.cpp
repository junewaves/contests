#include <bits/stdc++.h>
using namespace std;

struct segtree {
    int n;
    vector<int64_t> t;
    segtree(int n_) : n(n_), t(n_ * 2, 0) {}
    void add(int l, int r, int x) {
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) t[l++] += x;
            if (r & 1) t[--r] += x;
        }
    }
    int64_t sum(int i) {
        int64_t res = 0;
        for (i += n; i; i /= 2)
            res += t[i];
        return res;
    }
};

int n, q, timer = 0;
vector<int> ts, te;
vector<array<int, 2>> edges;
vector<vector<int>> adj;

void dfs(int u, int p) {
    ts[u] = timer++;
    for (int v : adj[u])
        if (v != p)
            dfs(v, u);
    te[u] = timer;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    edges.reserve(n - 1);
    adj.assign(n, {});
    ts.assign(n, 0);
    te.assign(n, 0);
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        --u, --v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    segtree st(n);
    cin >> q;
    while (q--) {
        int t, e, x;
        cin >> t >> e >> x;
        --e;
        auto [u, v] = edges[e];
        if (t == 2) swap(u, v);
        if (ts[u] < ts[v]) {
            st.add(0, n, x);
            st.add(ts[v], te[v], -x);
        } else {
            st.add(ts[u], te[u], x);
        }
    }
    for (int i = 0; i < n; i++)
        cout << st.sum(ts[i]) << '\n';
    return 0;
}
