#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, m;
    cin >> n >> m;
    ll d = n < m ? m / n : n / m;
    ll r = n < m ? m % n : n % m;
    if (r != 0 || (d & (d - 1)) != 0) {
        cout << -1 << '\n';
        return;
    }
    int k = -1;
    while (d) {
        k++;
        d >>= 1;
    }
    // cout << c << ' ';
    if (n == m) {
        cout << 0 << '\n';
    } else if (k <= 3) {
        cout << 1 << '\n';
    } else {
        cout << (k - 1) / 3 + 1 << '\n';
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
