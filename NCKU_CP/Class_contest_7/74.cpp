#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5 + 1;
int g[mxn];
struct edge {
    int u, v, w;
    bool operator<(const edge& o) const { return w < o.w; }
};
int Find(int v) {
    if (g[v] == v)
        return v;
    g[v] = Find(g[v]);
    return g[v];
}
void Union(int u, int v) {
    g[Find(v)] = Find(u);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge> adj;
    for (int i = 0; i < n; i++)
        g[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({ u, v, w });
    }
    sort(adj.begin(), adj.end());
    vector<int> mst;
    int min_cost = 0;
    for (int i = 0; i < m; i++) {
        edge& e = adj[i];
        int u = Find(e.u), v = Find(e.v);
        if (u != v) {
            Union(e.u, e.v);
            min_cost += e.w;
            mst.push_back(i);
            if (1 + mst.size() == n)
                break;
        }
    }
    int ans = 1e9;
    for (int x : mst) {
        int cost = 0, cnt = 0;
        for (int i = 0; i < n; i++)
            g[i] = i;
        for (int k = 0; k < m; k++) {
            if (k == x)
                continue;
            edge& E = adj[k];
            int a = Find(E.u), b = Find(E.v);
            if (a != b) {
                Union(E.u, E.v);
                cost += E.w;
                cnt++;
                if (1 + cnt == n)
                    break;
            }
        }
        if (cost < ans) {
            ans = cost;
        }
    }
    // cout << min_cost << endl;
    cout << ans << endl;
    return 0;
}
