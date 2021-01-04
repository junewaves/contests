#include <bits/stdc++.h>
using namespace std;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
constexpr int inf = 1e9 + 5;
vector<vector<int>> adj;
vector<int> dis, ans;
vector<bool> vis;

int dfs(int u) {
    vis[u] = true;
    int d = dis[u];
    for (int v : adj[u]) {
        if (dis[u] >= dis[v])
            d = min(d, dis[v]);
        else if (vis[v])
            d = min(d, ans[v]);
        else
            d = min(d, dfs(v));
    }
    return ans[u] = d;
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n, {});
    dis.assign(n, inf);
    ans.assign(n, inf);
    vis.assign(n, false);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }
    dis[0] = 0;
    minpq<pair<int, int>> pq;
    pq.emplace(0, 0);
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] != d) continue;
        for (int v : adj[u]) {
            if (dis[v] > d + 1) {
                dis[v] = d + 1;
                pq.emplace(dis[v], v);
            }
        }
    }
    dfs(0);
    for (int d : ans)
        cout << d << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
