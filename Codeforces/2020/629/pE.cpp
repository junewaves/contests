#include <bits/stdc++.h>
using namespace std;

int global_time;
vector<int> p, d, tin, tout;
vector<vector<int>> a;

void dfs(int u = 0, int parent = -1, int depth = 0) {
    p[u] = parent;
    d[u] = depth;
    tin[u] = global_time++;
    for (int v : a[u]) {
        if (parent != v)
            dfs(v, u, depth + 1);
    }
    tout[u] = global_time++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    p = d = tin = tout = vector<int>(n);
    a = vector<vector<int>>(n);
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    global_time = 0;
    dfs();
    for (int i = 0, m; i < q; i++) {
        cin >> m;
        vector<int> que(m);
        int fv = 0, mxd = 0;
        for (int& it : que) {
            cin >> it;
            --it;
            if (d[it] > mxd) {
                mxd = d[it];
                fv = it;
            }
        }
        for (int& it : que) {
            if (it != fv && it != 0) {
                it = p[it];
            }
        }
        bool ok = true;
        for (int j = 0; j < m && ok; j++) {
            if (tin[que[j]] > tin[fv] || tout[fv] > tout[que[j]]) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}