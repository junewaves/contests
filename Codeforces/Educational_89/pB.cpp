#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    vector<array<int, 2>> idx(m);
    for (int i = 0; i < m; i++)
        cin >> idx[i][0] >> idx[i][1];
    int l, r;
    l = r = x;
    for (int i = 0; i < m; i++) {
        if (l > idx[i][0] && l <= idx[i][1])
            l = idx[i][0];
        if (r < idx[i][1] && r >= idx[i][0])
            r = idx[i][1];
    }
    cout << r - l + 1 << '\n';
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
