// Kickstart 2020 Round B (4/19)
#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long ll;
ll x[1001];
void solve() {
    ll d, m = 0;
    int n;
    memset(x, 0, sizeof(x));
    vector<int> g;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = n - 1; i >= 0; i--)
        d -= (d % x[i]);
    cout << d << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _n;
    cin >> _n;
    for (int i = 1; i <= _n; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
