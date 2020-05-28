#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dep, low;
int n, ans;

void dfs(int u = 1, int p = -1, int d = 0) {
    dep[u] = low[u] = d;
    int cnt = d > 0;
    bool back_error = false;
    for (int v : adj[u]) {
        if (p != v) {
            if (dep[v] != -1) {
                low[u] = min(low[u], dep[v]);
                continue;
            }
            cnt++;
            dfs(v, u, d + 1);
            low[u] = min(low[u], low[v]);
            if (low[v] >= d)
                back_error = true;
        }
    }
    if (cnt > 1 && back_error)
        ++ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n && n > 0) {
        int u, v;
        adj = vector<vector<int>>(n + 1);
        dep = low = vector<int>(n + 1, -1);
        while (cin >> u && u > 0) {
            while (cin.get() != '\n') {
                cin >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        ans = 0;
        dfs();
        cout << ans << endl;
    }
}