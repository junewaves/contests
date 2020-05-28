#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    ll w;
    int u, v, id;
    bool operator<(const Edge& o) const { return w < o.w; };
    Edge(int a, int b, ll c, int d) : w(c), u(a), v(b), id(d) {}
};

// vector<int> group;
int group[1001];

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
    int n, m;
    cin >> n >> m;
    vector<Edge> e;
    // group = vector<int>(n);
    for (int j = 0; j <= n; j++)
        group[j] = j;
    ll w;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v >> w;
        e.emplace_back(u, v, w, i);
    }
    sort(e.begin(), e.end());
    vector<int> used;
    int con = 0;
    ll w_min = 0;
    for (int i = 0; i < m && con < n - 1; i++) {
        if (Find(e[i].u) != Find(e[i].v)) {
            w_min += e[i].w;
            Union(e[i].u, e[i].v);
            used.push_back(e[i].id);
            ++con;
        }
    }
    if (con != n - 1) {
        puts("-1 -1");
        return 0;
    }
    bool ok = false;
    ll w_alt = LLONG_MAX;
    for (int ignore_id : used) {
        con = 0;
        ll res = 0;
        for (int j = 0; j <= n; j++)
            group[j] = j;
        for (int i = 0; i < m && con < n - 1; i++) {
            if (e[i].id == ignore_id || Find(e[i].u) == Find(e[i].v))
                continue;
            Union(e[i].u, e[i].v);
            res += e[i].w;
            ++con;
        }
        if (con == n - 1) {
            ok = true;
            w_alt = min(w_alt, res);
        }
    }
    cout << w_min << " " << (ok ? w_alt : -1) << '\n';
    return 0;
}