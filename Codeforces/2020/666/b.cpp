#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int64_t& it : a)
        cin >> it;
    sort(a.begin(), a.end());
    int64_t ans = LLONG_MAX;
    for (int c = 1; c <= 500000; c++) {
        int64_t sum = 0;
        int64_t v = 1;
        bool bad = false;
        for (int i = 0; i < n; i++) {
            if (i) v *= c;
            if (v >= 1e18) {
                bad = true;
                break;
            }
            sum += abs(a[i] - v);
        }
        if (bad) break;
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}