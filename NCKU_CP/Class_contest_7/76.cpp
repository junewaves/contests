#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> planes(n);
    vector<array<int, 2>> ports(m);
    vector<vector<int>> edges(n + m);
    for (auto& x : planes)
        cin >> x[0] >> x[1] >> x[2];
    for (int u = 0; u < m; u++) {
        auto& y = ports[u];
        cin >> y[0] >> y[1];
        for (int v = 0; v < n; v++) {
            auto& x = planes[v];
            int dx = x[0] - y[0], dy = x[1] - y[1];
            if (dx * dx + dy * dy <= x[2] * x[2]) {
                edges[n + u].push_back(v);
                edges[v].push_back(n + u);
            }
        }
    }
    // bipartite matching
    int ans = 0;
    bitset<2001> vis;
    vector<int> mp(n + m, -1), mq(n + m, -1);
    function<bool(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (int v : edges[u]) {
            if (mq[v] == -1 || (!vis[mq[v]] && dfs(mq[v]))) {
                mp[u] = v;
                mq[v] = u;
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < n; i++) {
        vis.reset();
        if (dfs(i))
            ans++;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        if (~mp[i])
            cout << i + 1 << ' ' << mp[i] - n + 1 << '\n';
    return 0;
}