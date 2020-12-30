#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    int ans = n;
    for (int i = 1; (ll)i * i <= (ll)n; i++) {
        if (n % i == 0) {
            if (i <= k) {
                ans = min(ans, n / i);
            }
            if (n / i <= k) {
                ans = min(ans, i);
            }
        }
    }
    cout << ans << '\n';
    return;
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