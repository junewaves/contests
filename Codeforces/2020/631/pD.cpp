#include <bits/stdc++.h>
using namespace std;
#ifndef _VSCODE_DEBUG
#define endl '\n'
#endif
typedef long long int ll;
ll d, m;
int rec(ll bi1, ll a, int n, int level) {
    ll bi = bi1 ^ a;
    if (bi > bi1 || a == 0) {
        if (level == n) {
            return 1;
        } else {
            ll s = 0;
            for (int i = a + 1; i <= d; ++i) {
                s = (s + rec(bi, i, n, level + 1)) % m;
            }
            return s;
        }
    } else {
        return 0;
    }
}
void solve() {
    cin >> d >> m;
    ll s = 0;
    for (int i = 1; i <= d; i++) {
        s = (s + rec(0, 0, i, 0)) % m;
    }
    cout << s << endl;
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