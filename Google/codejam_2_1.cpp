#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll L, R;
    cin >> L >> R;
    bool sw = false;
    if (L < R) {
        swap(L, R);
        sw = true;
    }
    // bin search 1
    ll a = 0, b = 2e9, i, c1, c2;
    while (a < b) {
        ll m = (a + b + 1) / 2;
        if (m * (m + 1) / 2 > L - R)
            b = m - 1;
        else
            a = m;
    }
    i = a;
    L -= i * (i + 1) / 2;
    if (sw && L == R)
        sw = false;
    // bin search 2
    a = 0, b = 2e9;
    while (a < b) {
        ll m = (a + b + 1) / 2;
        if ((i + m) * m > L)
            b = m - 1;
        else
            a = m;
    }
    c1 = a;
    L -= (i + c1) * c1;
    // bin search 3
    a = 0, b = 2e9;
    while (a < b) {
        ll m = (a + b + 1) / 2;
        if ((i + 1 + m) * m > R)
            b = m - 1;
        else
            a = m;
    }
    c2 = a;
    R -= (i + 1 + c2) * c2;
    if (sw)
        swap(L, R);
    cout << i + c1 + c2 << " " << L << " " << R << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cout << "Case #" << c << ": ";
        solve();
    }
}
