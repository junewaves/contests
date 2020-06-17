#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (m <= n / k) {
        cout << m << '\n';
        return;
    }
    m -= n / k;
    int d = (m + k - 2) / (k - 1);
    cout << (n / k) - d << '\n';
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
