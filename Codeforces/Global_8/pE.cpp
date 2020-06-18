#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> od(n, 0), id(n, 0);
    vector<vector<int>> Out(n), In(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        ++od[u], ++id[v];
        Out[u].push_back(v);
        In[v].push_back(u);
    }
    vector<int> ans;
    for (int t = 1; t <= (4 * n / 7); t++) {
        int mxo = 0, mxi = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            if (od[i] > mxo || (od[i] + id[i] > mxo + mxi)) {
                mxo = od[i];
                mxi = id[i];
                idx = i;
            }
        }
        if (idx == -1)
            break;
        od[idx] = 0;
        id[idx] = 0;
        for (int v : Out[idx])
            if (id[v])
                id[v]--;
        for (int v : In[idx])
            if (od[v])
                od[v]--;
        ans.push_back(idx + 1);
    }
    cout << ans.size() << '\n';
    for (int v : ans)
        cout << v << ' ';
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
