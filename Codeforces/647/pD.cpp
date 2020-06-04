#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<set<int>> adj;
void solve() {
    int n, m;
    cin >> n >> m;
    adj = vector<set<int>>(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, --u, --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 0; i < n; i++) {
        for (int j : adj[i])
            cout << j << " ";
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
