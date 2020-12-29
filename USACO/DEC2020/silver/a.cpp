#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<vector<int>> adj;

void dfs(int u, int p, int d) {
    int ch = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
        ch++;
    }
    int cnt = 1, day = 0;
    while (cnt < ch) cnt *= 2, day++;
    ans += day + ch - 1;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    adj.assign(n, {});
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, 0);
    cout << ans << '\n';
    return 0;
}