#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mxn = 3e5 + 1;
vector<int> a[mxn];
int ok[mxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q, k;
    cin >> n >> m >> q >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    queue<int> que;
    que.push(k);
    ok[k] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : a[u]) {
            if (!ok[v]) {
                ok[v] = u + 1;
                que.push(v);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        cout << ok[t] - 1 << ' ';
    }
    cout << endl;
    return 0;
}
