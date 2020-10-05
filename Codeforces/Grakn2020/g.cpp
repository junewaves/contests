#include <atcoder/modint>
#include <atcoder/convolution>
#include <bits/stdc++.h>
using namespace std;
using mint = atcoder::modint998244353;

int n;
vector<int> g, h;
vector<vector<mint>> dp;
int get(int u) {
    return g[u] < 0 ? u : g[u] = get(g[u]);
}
void uni(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) {
        h[u]++;
    } else {
        if (g[u] > g[v]) swap(u, v);
        dp[u] = atcoder::convolution(dp[u], dp[v]);
        h[u] += h[v] + 1;
        g[u] += g[v];
        g[v] = u;
    }
    int sz = -g[u];
    if (h[u] == sz * (sz - 1) / 2) {
        dp[u][1] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    g.resize(n, -1);
    h.resize(n, 0);
    dp.resize(n, {0, 1});
    vector<vector<int>> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (i < j) {
                b.push_back({w, i, j});
            }
        }
    }
    sort(b.begin(), b.end());
    for (auto& c : b) {
        uni(c[1], c[2]);
    }
    int u = min_element(g.begin(), g.end()) - g.begin();
    for (int i = 1; i <= n; i++) {
        cout << dp[u][i].val() << " \n"[i == n];
    }
    return 0;
}