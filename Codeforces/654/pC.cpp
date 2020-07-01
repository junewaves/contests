#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    if (m <= min(a, b) && a + b - m >= n)
        cout << "Yes\n";
    else
        cout << "No\n";
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