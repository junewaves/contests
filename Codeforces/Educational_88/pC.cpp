#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll h, c, t;
    cin >> h >> c >> t;
    if (h == t) {
        cout << 1 << '\n';
        return;
    }
    if (h + c >= t * 2) {
        cout << 2 << '\n';
        return;
    }
    ll lo = 0, hi = 1e7;
    while (lo < hi) {
        int m = (lo + hi + 1) / 2;
        if (m * (h + c) + h >= (2 * m + 1) * t) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }
    hi = lo + 1;
    if ((lo * (h + c) + h - (2 * lo + 1) * t) * (2 * hi + 1) >
        ((2 * hi + 1) * t - (hi * (h + c) + h)) * (2 * lo + 1)) {
        cout << 2 * hi + 1 << '\n';
    } else {
        cout << 2 * lo + 1 << '\n';
    }
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
