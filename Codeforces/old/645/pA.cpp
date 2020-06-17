#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m, ans;
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    if (n % 2) {
        ans = (n - 1) * m / 2 + (m + 1) / 2;
    } else {
        ans = n / 2 * m;
    }
    cout << ans << '\n';
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
