#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> a, an;
vector<int> dep;
void dfs(int u, int p, int d) {
    dep[u] = d;
    for (int v : a[u]) {
        if (v == p) continue;
        an[v][0] = u;
        for (int i = 1; i <= log2(d + 1); i++) {
            if (an[v][i - 1] != -1)
                an[v][i] = an[an[v][i - 1]][i - 1];
        }
        dfs(v, u, d + 1);
    }
}
int LCA(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    while (dep[u] != dep[v]) {
        u = an[u][log2(dep[u] - dep[v])];
    }
    if (u == v)
        return u;
    for (int i = log2(dep[u]); i >= 0; i--) {
        if (an[u][i] != an[v][i])
            u = an[u][i], v = an[v][i];
    }
    return an[u][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v, d;
    cin >> n >> m;
    d = log2(n);
    a = vector<vector<int>>(n);
    an = vector<vector<int>>(n, vector<int>(d, -1));
    dep = vector<int>(n, -1);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(0, -1, 0);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
    return 0;
}
