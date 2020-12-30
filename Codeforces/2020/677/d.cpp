#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> g(n, -1);
    auto get = [&](int u) {
        while (g[u] >= 0) {
            if (g[g[u]] >= 0) g[u] = g[g[u]];
            u = g[u];
        }
        return u;
    };
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] != a[j] && get(i) != get(j)) {
                ans.emplace_back(i + 1, j + 1);
                int x = get(i), y = get(j);
                if (g[x] > g[y]) swap(x, y);
                g[x] += g[y];
                g[y] = x;
            }
        }
        if ((int)ans.size() == n - 1) {
            break;
        }
    }
    if ((int)ans.size() != n - 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}