#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, --u, --v;
        edges[v].push_back(u);
    }
    vector<int> ans;
    vector<int> path(n);
    for (int i = 0; i < n; i++) {
        for (int j : edges[i]) {
            path[i] = max(path[i], path[j] + 1);
        }
        if (path[i] == 2){
            ans.push_back(i + 1);
            path[i] = -1;
        }
    }
    cout << ans.size() << '\n';
    for (int u : ans)
        cout << u << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
