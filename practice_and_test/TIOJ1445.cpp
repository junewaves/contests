#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
};

int n, m = 0, _m;
vector<int> group;

int Find(int u) {
    if (group[u] == u)
        return u;
    return group[u] = Find(group[u]);
}

void Union(int u, int v) {
    group[Find(u)] = Find(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> _m;
    vector<edge> e(_m);
    group = vector<int>(n);
    vector<vector<pair<int, int>>> adj_full(n);
    for (int i = 0; i < n; i++)
        group[i] = i;
    for (int i = 0, u, v, w; i < _m; i++) {
        cin >> u >> v >> w;
        if (u != v) {
            e[m].u = --u;
            e[m].v = --v;
            e[m].w = w;
            ++m;
            adj_full[u].emplace_back(v, w);
            adj_full[v].emplace_back(u, w);
        }
    }
    if (!m) {
        cout << "-1 -1\n";
        return 0;
    }
    e.resize(m);
    sort(e.begin(), e.end(),
         [](const edge& x, const edge& y) { return x.w < y.w; });
    vector<edge> used;
    vector<vector<pair<int, int>>> adj(n);
    int con = 0;
    long long w_min = 0, w_alt = 0x3f3f3f3f;
    for (int i = 0; i < m; i++) {
        if (Find(e[i].u) != Find(e[i].v)) {
            Union(e[i].u, e[i].v);
            w_min += e[i].w;
            used.push_back(e[i]);
            ++con;
            adj[e[i].u].emplace_back(e[i].v, e[i].w);
            adj[e[i].v].emplace_back(e[i].u, e[i].w);
        }
    }
    if (con != n - 1) {
        cout << "-1 -1\n";
        return 0;
    } else if (con == m) {
        cout << w_min << " -1\n";
        return 0;
    }
    /*
    function<int(int, int, int)> dfs = [&](int u, int p, int t) {
        int ans = -1, v, w;
        for (const auto& pp : adj[u]) {
            tie(v, w) = pp;
            if (v == p)
                continue;
            if (v == t)
                return w;
            int ret = dfs(v, u, t);
            if (ret != -1) {
                ans = max(w, ret);
            }
        }
        return ans;
    };*/
    function<void(int, int, int)> dfs2 = [&](int u, int g, int be) {
        group[u] = g;
        for (const auto& v : adj[u]) {
            if (!group[v.first] && v.first != be) {
                dfs2(v.first, g, be);
            }
        }
    };
    // n * n
    for (const edge& E : used) {
        for (int i = 0; i < n; i++)
            group[i] = 0;
        int u = E.u, v = E.v;
        dfs2(u, 1, v);
        dfs2(v, 2, u);
        int w = 0x3f3f3f3f;
        for (const auto& pp : adj_full[u]) {
            if (group[u] != group[pp.first] && v != pp.first) {
                w = min(w, pp.second);
            }
        }
        for (const auto& pp : adj_full[v]) {
            if (group[v] != group[pp.first] && u != pp.first) {
                w = min(w, pp.second);
            }
        }
        w_alt = min(w_alt, w_min + w - E.w);
    }
    cout << w_min << " " << w_alt << '\n';
    return 0;
}
