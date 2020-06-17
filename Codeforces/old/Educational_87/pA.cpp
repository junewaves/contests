#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b >= a) {
        cout << b << '\n';
        return;
    }
    if (c <= d) {
        cout << "-1\n";
        return;
    }
    ll e = (a - b + (c - d) - 1) / (c - d);
    cout << b + c * e << '\n';
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
