#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge {
    int u, v, w, id;
    bool operator<(const Edge& o) const { return w < o.w; }
    Edge(int a, int b, int c, int d) : u(a), v(b), w(c), id(d) {}
};
struct Node {
    int w, id;
    bool operator<(const Node& o) const { return w < o.w; }
    Node(int a, int b) :  w(a), id(b) {}
};
vector<Edge> edges;
vector<vector<Node>> adj;
vector<vector<int>> anc, wmax;
vector<int> group, depth;
int Find(int u) {
    if (group[u] == u)
        return u;
    return group[u] = Find(group[u]);
}
void Union(int u, int v) {
    group[Find(u)] = Find(v);
}
void dfs(int u, int p, int w) {
    int dep = (p == -1 ? 0 : depth[p] + 1);
    depth[u] = dep;
    wmax[u][0] = w;  // largest edge weight from u to i'th ancestor
    for (auto node : adj[u]) {
        int v = node.id;
        if (v == p)
            continue;
        anc[v][0] = u;
        for (int i = 1; i <= log2(dep + 1); i++) {
            if (anc[v][i - 1] == -1)
                break;
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
            wmax[v][i] = max(wmax[v][i - 1], wmax[anc[v][i - 1]][i - 1]);
        }
        dfs(v, u, node.w);
    }
}
int LCA_weight(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int ans = -1;
    while (depth[u] != depth[v]) {
        int i = log2(depth[u] - depth[v]);
        ans = max(ans, wmax[u][i]);
        u = anc[u][i];
    }
    if (u == v)
        return ans;
    for (int i = log2(depth[u]); i >= 0; i--) {
        if (anc[v][i] != anc[u][i]) {
            ans = max({ ans, wmax[u][i], wmax[v][i] });
            v = anc[v][i];
            u = anc[u][i];
        }
    }
    ans = max({ ans, wmax[u][0], wmax[v][0] });
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    group.resize(n);
    edges.reserve(m);
    iota(group.begin(), group.end(), 0);  // group[i] = i
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w, i);
    }
    sort(edges.begin(), edges.end());
    // find MST
    int cnt = 1, min_cost = 0;
    vector<bool> used(m);
    for (const Edge& e : edges) {
        if (Find(e.u) == Find(e.v))
            continue;
        Union(e.u, e.v);
        adj[e.u].emplace_back(e.v, e.w);
        adj[e.v].emplace_back(e.u, e.w);
        used[e.id] = true;
        min_cost += e.w;
        if (++cnt == n)
            break;
    }
    // find ancestor
    int logd = log2(n);
    wmax.resize(n, vector<int>(logd, -1));
    anc.resize(n, vector<int>(logd, -1));
    depth.resize(n, -1);
    dfs(0, -1, 0);
    // find second best MST
    int ans = 1e9;
    for (const Edge& e : edges) {
        if (used[e.id])  
            continue;
        int x = LCA_weight(e.u, e.v); // largest weight in the cycle created
        ans = min(ans, min_cost + e.w - x);
    }
    cout << ans << endl;
    return 0;
}