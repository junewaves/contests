#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[46];
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (n > m)
        swap(n, m);
    for (int i = 0; i < 45; i++) {
        if (f[i + 1] * m + f[i] * n > k) {
            cout << i << endl;
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    f[1] = f[2] = 1;
    for (int i = 3; i < 46; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int _n;
    cin >> _n;
    while (_n--) {
        solve();
    }
    return 0;
}
