#include <bits/stdc++.h>
using namespace std;

constexpr int mxn = 2e5 + 5;
int n, a[mxn], delta[mxn];
int tour_order, ts[mxn], te[mxn];
vector<int> adj[mxn];
set<pair<int, int>> seen[mxn];

void tour(int u, int p) {
    ts[u] = tour_order++;
    for (int v : adj[u])
        if (v != p) tour(v, u);
    te[u] = tour_order;
}

void dfs(int u, int p) {
    bool collision = false;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            auto it = seen[v].lower_bound({a[u], -1});
            if (it != seen[v].end() && it->first == a[u]) {
                if (collision) {
                    cout << "0\n";
                    exit(0);
                }
                delta[ts[1]]++;
                delta[ts[v]]--;
                delta[te[v]]++;
                delta[te[1]]--;
                collision = true;
            }
            if (seen[v].size() > seen[u].size())
                swap(seen[v], seen[u]);
            seen[u].merge(seen[v]);
       }
    }
    auto lo = seen[u].lower_bound({a[u], -1});
    auto up = seen[u].lower_bound({a[u] + 1, -1});
    if (lo != up) {
        for (auto it = lo; it != up; ++it) {
            delta[ts[it->second]]++;
            delta[te[it->second]]--;
        }
        seen[u].erase(lo, up);
    }
    seen[u].emplace(a[u], u);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    tour(1, -1);
    dfs(1, -1);
    map<int, vector<int>> mp;
    for (const auto &[val, idx] : seen[1])
        mp[val].push_back(idx);
    for (const auto &[val, vec] : mp) {
        if (int(vec.size()) > 1) {
            for (int u : vec) {
                delta[ts[u]]++;
                delta[te[u]]--;
            }
        }
    }
    int ans = 0;
    for (int i = 0, s = 0; i < n; i++) {
        s += delta[i];
        ans += (s == 0);
    }
    cout << ans << '\n';
    return 0;
}