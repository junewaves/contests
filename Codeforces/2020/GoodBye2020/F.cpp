#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> g;
    dsu(int n) : g(n, -1) {}
    int get(int u) {
        return g[u] < 0 ? u : g[u] = get(g[u]);
    }
    bool merge(int u, int v) {
        u = get(u), v = get(v);
        if (u == v) return false;
        if (g[u] > g[v]) swap(u, v);
        g[u] += g[v];
        g[v] = u;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int MOD = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<int> used;
    dsu g(m + 1);
    int sz = 1;
    for (int i = 0, k, u, v; i < n; i++) {
        cin >> k;
        if (k == 1)
            u = 0, cin >> v;
        else
            cin >> u >> v;
        if (g.merge(u, v)) {
            used.push_back(i + 1);
            sz *= 2;
            if (sz >= MOD) sz -= MOD;
        }
    }
    cout << sz << ' ' << used.size() << '\n';
    for (int id : used)
        cout << id << ' ';
    return 0;
}