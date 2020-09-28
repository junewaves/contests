#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& it : a) cin >> it;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (k - a[i]) / a[0];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}