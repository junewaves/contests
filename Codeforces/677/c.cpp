#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int ans = -2;
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            bool ok = false;
            if (i > 0)
                ok |= a[i] > a[i - 1];
            if (i + 1 < n)
                ok |= a[i] > a[i + 1];
            if (ok) {
                ans = i;
                break;
            }
        }
    }
    cout << ans + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}