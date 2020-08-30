#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, r, ans;
    cin >> n >> r;
    if (r >= n) {
        ans = (n - 1) * n / 2 + 1;
    } else {
        ans = (r + 1) * r / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}