#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    int d = min((n - m), m);
    int ans = d;
    n -= d + d;
    m -= d;
    d = min(n, m) / 3;
    ans += d * 2;
    n -= d * 3;
    m -= d * 3;
    if (n >= 1 && m >= 2)
        ans++, n--, m -= 2;
    if (n >= 2 && m >= 1)
        ans++, n -= 2, m--;
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
