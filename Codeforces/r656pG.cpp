#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// constexpr int mxn = 2e5 + 1;
// int cnt[2], a[2][mxn], color[mxn], group[mxn];
// vector<int> pos[mxn], final;
// vector<pair<int, int>> adj[mxn];
int cnt[2];
vector<int> a[2], color, group, final;
vector<vector<int>> pos;
vector<vector<pair<int, int>>> adj;

void dfs(int u, int c, int g) {
    cnt[c]++;
    color[u] = c;
    group[u] = g;
    for (const auto& [v, chg] : adj[u])
        if (color[v] == -1)
            dfs(v, c ^ chg, g);
}

void solve() {
    int n;
    cin >> n;
    // for (int i = 0; i < n; i++)
    //     pos[i].clear(), adj[i].clear();
    pos = vector<vector<int>>(n);
    adj = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < 2; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            pos[--a[i][j]].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        if (pos[i].size() != 2) {
            cout << "-1\n";
            return;
        }
        int c1 = pos[i][0], c2 = pos[i][1];
        if (c1 == c2) continue;
        // int row1 = (i != a[0][c1]), row2 = (i != a[0][c2]);
        int change = (i == a[0][c1]) == (i == a[0][c2]);
        adj[c1].emplace_back(c2, change);
        adj[c2].emplace_back(c1, change);
    }
    final.clear();
    color = group = vector<int>(n, -1);
    // memset(color, -1, 4 * n);
    // memset(group, -1, 4 * n);
    int g = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            cnt[0] = cnt[1] = 0;
            dfs(i, 0, g);
            ++g;
            ans += min(cnt[0], cnt[1]);
            final.push_back(cnt[0] < cnt[1]);
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++)
        if (color[i] != final[group[i]])
            cout << i + 1 << ' ' ;
    cout << '\n';
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