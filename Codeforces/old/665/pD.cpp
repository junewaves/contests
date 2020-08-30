#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

constexpr int mod = 1e9 + 7;
int n;
vector<vector<int>> adj;
vector<ll> weights;

int dfs(int u, int p) {
    int ch = 0;
    for (int v : adj[u]) {
        if (v != p) {
            int c = dfs(v, u);
            weights.push_back((ll)c * (n - c));
            ch += c;
        }
    }
    return ch + 1;
}

void solve() {
    cin >> n;
    weights.clear();
    adj.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    int m;
    cin >> m;
    vector<ll> f(m);
    for (ll& it : f)
        cin >> it;
    sort(weights.rbegin(), weights.rend());
    sort(f.rbegin(), f.rend());
    assert(n - 1 == (int)weights.size());
    int j = 0;
    for (int i = n - 1; i < m; i++, j++) {
        f[j + 1] = f[j] * f[j + 1] % mod;
    }
    ll ans = 0LL;
    for (int i = 0; i < n - 1; i++, j++) {
        if (j < m)
            ans = (ans + weights[i] * f[j]) % mod;
        else
            ans = (ans + weights[i]) % mod;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}